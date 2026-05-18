*This project has been created as part of the 42 curriculum by tsito, ksaotome.*

# push_swap

## Description

`push_swap` is a 42 group project about sorting integers with two stacks, `a` and `b`, using only a limited instruction set. The program receives a list of unique integers, builds the initial stack `a` from them, and prints a sequence of Push_swap operations to standard output so that stack `a` becomes sorted in ascending order and stack `b` becomes empty.

The goal is not only correctness, but also reducing the number of generated operations. This repository also supports runtime strategy selection and an optional benchmark mode required by the subject.

### Contributors

- `tsito`: parsing, validation, stack initialization, operation integration, radix sorting, benchmark mode, build integration.
- `ksaotome`: chunk sorting, stack utilities, small-sort related work, strategy improvements, algorithm review.

Both contributors are expected to understand and explain every part of the project during evaluation.

## Instructions

Build:

```sh
make
```

Clean object files:

```sh
make clean
```

Remove generated files:

```sh
make fclean
```

Rebuild:

```sh
make re
```

Run:

```sh
./push_swap 2 1 3 6 5 8
```

The output must contain only Push_swap operations, one per line, unless `--bench` is enabled. Benchmark information is sent to standard error, so the operation stream on standard output remains compatible with the provided checker.

Example with checker:

```sh
ARG="4 67 3 87 23" ./push_swap --complex $ARG | ./checker_Mac $ARG
```

Benchmark mode:

```sh
ARG="4 67 3 87 23" ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_Mac $ARG
cat bench.txt
```

### Accepted Input

The program accepts:

- A list of integers.
- Quoted groups such as `"2 1 3"`.
- Negative and positive values.
- Optional strategy flags.
- Optional `--bench` flag.

The first integer is the top of stack `a`.

If no argument is provided, the program exits without printing anything.

On error, the program prints:

```txt
Error
```

to standard error.

Errors include:

- Non-integer arguments.
- Values outside the `int` range.
- Duplicate values.
- Invalid option names.
- Missing numeric input after options.

### Strategy Options

| Option | Strategy | Intended class |
| --- | --- | --- |
| `--simple` | Selection-style min extraction | `O(n^2)` |
| `--medium` | Chunk-based sorting with about `√n` chunks | `O(n√n)` |
| `--complex` | LSD radix sort on normalized indexes | `O(n log n)` |
| `--adaptive` | Selects an internal strategy from the disorder value | mixed |

If no strategy selector is provided, `--adaptive` is used by default.

The subject requires the binary to embed Simple `O(n^2)`, Medium `O(n√n)`, Complex `O(n log n)`, and Adaptive strategies. The current `--complex` implementation uses LSD radix sort on normalized indexes, which gives a clear `O(n log n)` upper bound in the Push_swap operation model.

### Allowed Operations

| Operation | Meaning |
| --- | --- |
| `sa` | Swap the first two elements of stack `a`. |
| `sb` | Swap the first two elements of stack `b`. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Push the top of `b` to the top of `a`. |
| `pb` | Push the top of `a` to the top of `b`. |
| `ra` | Rotate `a` upward; the first element becomes the last. |
| `rb` | Rotate `b` upward; the first element becomes the last. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | Reverse rotate `a`; the last element becomes the first. |
| `rrb` | Reverse rotate `b`; the last element becomes the first. |
| `rrr` | `rra` and `rrb` at the same time. |

### Disorder

Disorder measures how far the initial stack is from being sorted. It is computed before any move is performed.

For every pair `(i, j)` where `i < j`, the pair is counted as a mistake when `a[i] > a[j]`. The final disorder is:

```txt
mistakes / total_pairs
```

The value is between `0` and `1`:

- `0`: already sorted.
- `1`: worst possible order.
- Between `0` and `1`: partially sorted.

## Algorithm Details

### Simple: Selection-style min extraction

`--simple` repeatedly rotates the current minimum index to the top of stack `a`, pushes it to stack `b`, and finally pushes all elements back to `a`.

High-level flow:

```txt
while size(a) > 1:
    rotate minimum of a to top
    pb
while b is not empty:
    pa
```

Operation model:

- Each minimum search/rotation can cost up to `O(n)` operations.
- This is repeated `n` times.
- Upper bound: `O(n^2)` Push_swap operations.
- Extra memory: `O(1)` apart from the stack nodes already used by the program.

### Medium: Chunk-based sorting

`--medium` divides normalized indexes into about `√n` chunks.

Flow:

1. Normalize values into indexes.
2. Compute `chunk_count = √n`.
3. Push each index range from `a` to `b`.
4. Push values back from `b` to `a` in descending index order, rotating `b` in the shorter direction before each `pa`.

Operation model:

- The number of chunks is about `√n`.
- Each chunk scan may rotate through stack `a`.
- Rebuilding stack `a` from `b` searches for the next target index and rotates toward it.
- Intended upper bound: `O(n√n)` Push_swap operations for the chunk-selection phase.
- Extra memory: `O(1)` apart from existing stack nodes.

### Complex: LSD radix sort

`--complex` uses LSD radix sort on normalized indexes. Since each input value is first mapped to an index in the range `0..n-1`, negative values do not require special bit handling.

Flow:

1. Compute the number of bits required to represent the largest index.
2. For each bit from least significant to most significant:
   - inspect each element of stack `a` once,
   - push elements whose current bit is `0` to `b`,
   - rotate elements whose current bit is `1` inside `a`,
   - push all elements from `b` back to `a`.

For each bit, every element causes either one `pb` or one `ra`, and every element pushed to `b` is restored with `pa`. The number of processed bits is about `log2(n)`, so the generated operation count is bounded by `O(n log n)`. Extra memory is `O(1)` apart from the existing stack nodes.

### Adaptive

`--adaptive` measures disorder first and chooses an internal strategy:

| Disorder range | Strategy |
| --- | --- |
| `disorder < 0.2` | Simple |
| `0.2 <= disorder < 0.5` | Medium |
| `disorder >= 0.5` | Complex |

Rationale:

- Low disorder inputs may already be close to sorted, so a simple extraction strategy is acceptable.
- Medium disorder inputs benefit from range-based chunking.
- High disorder inputs use a cost-based strategy to reduce unnecessary rotations.

### Benchmark Mode

`--bench` prints benchmark information to standard error after sorting. It does not change the operation stream on standard output.

Displayed information:

- Disorder percentage with two decimals.
- Selected strategy name and complexity class label.
- Total number of operations.
- Count for each operation type: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

Example:

```txt
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Performance Targets

The subject defines the following operation-count targets:

| Input size | Minimum pass | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 random numbers | `< 2000` | `< 1500` | `< 700` |
| 500 random numbers | `< 12000` | `< 8000` | `< 5500` |

Evaluation uses the provided checker.

## Resources

- [ラディックスソート（基数ソート）の仕組みを徹底解説！アニメーションで学ぶ「桁を利用する」ソート【ソートアルゴリズム入門】#14](https://tukumolog.com/radix-sort-introduction/)
- AI usage: AI was used to discuss parsing edge cases, operation-count reasoning, README wording and benchmark-mode design. Generated suggestions were reviewed and adapted manually; final responsibility for the implementation remains with the contributors.

---

## Description

`push_swap` は、2つのスタック `a` / `b` と限られた命令だけを使って整数列を昇順に並べる 42 のグループ課題である。プログラムは重複のない整数列を受け取り、初期スタック `a` を作成し、最終的に `a` が昇順、`b` が空になるような Push_swap 命令列を標準出力へ出力する。

この課題の目的は、正しくソートするだけではなく、出力する操作数をできるだけ少なくすることである。このリポジトリでは、実行時の戦略選択と、subject で要求される任意のベンチマークモードにも対応している。

### Contributors

- `tsito`: パース、バリデーション、スタック初期化、操作関数の統合、radix ソート、ベンチマークモード、ビルド設定。
- `ksaotome`: チャンクソート、スタックユーティリティ、小規模ソート関連、戦略改善、アルゴリズムレビュー。

評価時には、両者がプロジェクト全体を説明できる必要がある。

## Instructions

ビルド:

```sh
make
```

オブジェクトファイル削除:

```sh
make clean
```

生成物削除:

```sh
make fclean
```

再ビルド:

```sh
make re
```

実行:

```sh
./push_swap 2 1 3 6 5 8
```

通常の出力は Push_swap 命令のみである。`--bench` を有効にした場合でも、ベンチマーク情報は標準エラーへ出るため、標準出力の操作列は checker にそのまま渡せる。

checker 使用例:

```sh
ARG="4 67 3 87 23" ./push_swap --complex $ARG | ./checker_Mac $ARG
```

ベンチマークモード:

```sh
ARG="4 67 3 87 23" ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_Mac $ARG
cat bench.txt
```

### 入力仕様

対応している入力:

- 整数列。
- `"2 1 3"` のようなクォートされたまとまり。
- 正の数と負の数。
- 任意の戦略フラグ。
- 任意の `--bench` フラグ。

最初の整数がスタック `a` の top になる。

引数がない場合は何も表示せず終了する。

エラー時は標準エラーへ次を出力する。

```txt
Error
```

エラー例:

- 整数ではない引数。
- `int` 範囲外の値。
- 重複した値。
- 不正なオプション名。
- オプションだけで数値がない入力。

### 戦略オプション

| オプション | 戦略 | 意図している計算量 |
| --- | --- | --- |
| `--simple` | 選択ソート風の最小値抽出 | `O(n^2)` |
| `--medium` | 約 `√n` 個のチャンクを使うチャンクソート | `O(n√n)` |
| `--complex` | 正規化済み index に対する LSD radix sort | `O(n log n)` |
| `--adaptive` | disorder に応じて内部戦略を選択 | 複合 |

戦略指定がない場合は `--adaptive` がデフォルトである。

subject は、Simple `O(n^2)`, Medium `O(n√n)`, Complex `O(n log n)`, Adaptive の4戦略をバイナリに含めることを要求している。現在の `--complex` は、正規化済み index に対する LSD radix sort を使うため、Push_swap 操作数モデルで `O(n log n)` の上界を説明できる。

### 使用可能な命令

| 命令 | 意味 |
| --- | --- |
| `sa` | スタック `a` の先頭2要素を交換する。 |
| `sb` | スタック `b` の先頭2要素を交換する。 |
| `ss` | `sa` と `sb` を同時に行う。 |
| `pa` | `b` の先頭要素を `a` の先頭へ移す。 |
| `pb` | `a` の先頭要素を `b` の先頭へ移す。 |
| `ra` | `a` を上方向に回転し、先頭要素を末尾へ送る。 |
| `rb` | `b` を上方向に回転し、先頭要素を末尾へ送る。 |
| `rr` | `ra` と `rb` を同時に行う。 |
| `rra` | `a` を下方向に回転し、末尾要素を先頭へ送る。 |
| `rrb` | `b` を下方向に回転し、末尾要素を先頭へ送る。 |
| `rrr` | `rra` と `rrb` を同時に行う。 |

### Disorder

disorder は、初期スタックがどれだけソート済み状態から離れているかを表す。命令を1つも実行する前に計算する。

すべてのペア `(i, j)` について `i < j` かつ `a[i] > a[j]` のとき、そのペアを mistake として数える。

```txt
mistakes / total_pairs
```

値は `0` から `1` である。

- `0`: すでにソート済み。
- `1`: 最悪の並び。
- `0` と `1` の間: 一部は整っているが乱れている。

## アルゴリズム詳細

### Simple: 選択ソート風の最小値抽出

`--simple` は、現在の最小 index をスタック `a` の top へ回転し、`b` へ push する。最後に `b` から `a` へ戻す。

流れ:

```txt
while size(a) > 1:
    a の最小値を top へ回転
    pb
while b is not empty:
    pa
```

操作数モデル:

- 各最小値の移動に最大 `O(n)` 操作かかる。
- それを `n` 回繰り返す。
- 上界は `O(n^2)` Push_swap 操作である。
- 追加メモリは、既存のスタックノードを除けば `O(1)` である。

### Medium: チャンクベースソート

`--medium` は、正規化済み index を約 `√n` 個のチャンクに分ける。

流れ:

1. 値を index に正規化する。
2. `chunk_count = √n` を計算する。
3. 各 index 範囲を `a` から `b` へ push する。
4. `b` から降順 index で値を探し、短い方向に回転してから `pa` で `a` に戻す。

操作数モデル:

- チャンク数は約 `√n` である。
- 各チャンクの探索で `a` を回転する。
- `b` から戻すときは対象 index を探して短い方向へ回転する。
- チャンク選択部分の意図した上界は `O(n√n)` Push_swap 操作である。
- 追加メモリは、既存のスタックノードを除けば `O(1)` である。

### Complex: LSD radix sort

`--complex` は、正規化済み index に対して LSD radix sort を行う。入力値は先に `0..n-1` の index へ変換されるため、負数に対する特別な bit 処理は不要である。

流れ:

1. 最大 index を表すために必要な bit 数を計算する。
2. 下位 bit から上位 bit まで順に処理する。
3. 各 bit について、スタック `a` の各要素を1回ずつ見る。
4. 対象 bit が `0` の要素は `pb` で `b` へ送る。
5. 対象 bit が `1` の要素は `ra` で `a` の中に残す。
6. `b` の要素をすべて `pa` で `a` に戻す。

各 bit について、すべての要素は `pb` または `ra` を1回行う。さらに `b` に送った要素は `pa` で戻す。処理する bit 数はおよそ `log2(n)` であるため、生成される操作数の上界は `O(n log n)` である。追加メモリは、既存のスタックノードを除けば `O(1)` である。

### Adaptive

`--adaptive` は最初に disorder を測定し、内部戦略を選ぶ。

| disorder 範囲 | 使用戦略 |
| --- | --- |
| `disorder < 0.2` | Simple |
| `0.2 <= disorder < 0.5` | Medium |
| `disorder >= 0.5` | Complex |

理由:

- disorder が低い入力はほぼ整っているため、単純な抽出戦略でも許容できる。
- 中程度の disorder では、範囲ベースのチャンク分割が有効である。
- 高 disorder では、不要な回転を減らすためにコストベース戦略を使う。

### ベンチマークモード

`--bench` は、ソート後にベンチマーク情報を標準エラーへ出力する。標準出力の操作列は変更しない。

表示内容:

- 小数2桁の disorder パーセント。
- 選択された戦略名と計算量ラベル。
- 合計操作数。
- 各命令 `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` の回数。

例:

```txt
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### 性能目標

subject では、以下の操作数目標が定義されている。

| 入力数 | 合格最低条件 | 良好 | 優秀 |
| --- | ---: | ---: | ---: |
| 100 random numbers | `< 2000` | `< 1500` | `< 700` |
| 500 random numbers | `< 12000` | `< 8000` | `< 5500` |

評価では提供された checker により確認される。

## Resources

- [ラディックスソート（基数ソート）の仕組みを徹底解説！アニメーションで学ぶ「桁を利用する」ソート【ソートアルゴリズム入門】#14](https://tukumolog.com/radix-sort-introduction/)
- AI 利用: パースの境界ケース、操作数の考え方、README の構成、ベンチマークモード設計。生成された提案は手動で確認・修正しており、最終的な実装責任は貢献者にある。
