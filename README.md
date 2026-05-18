*This project has been created as part of the 42 curriculum by tsito, ksaotome.*

# push_swap

## English

### Description

`push_swap` is a 42 group project about sorting integers with two stacks, `a` and `b`, using only a limited instruction set. The program receives a list of unique integers, builds the initial stack `a` from them, and prints a sequence of Push_swap operations to standard output so that stack `a` becomes sorted in ascending order and stack `b` becomes empty.

The goal is not only correctness, but also reducing the number of generated operations. This repository also supports runtime strategy selection and an optional benchmark mode required by the subject.

### Contributors

- `tsito`: parsing, validation, stack initialization, operation integration, Turk-style sorting, benchmark mode, build integration.
- `ksaotome`: chunk sorting, stack utilities, small-sort related work, strategy improvements, algorithm review.

Both contributors are expected to understand and explain every part of the project during evaluation.

### Instructions

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
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_Mac $ARG
```

Benchmark mode:

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_Mac $ARG
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
| `--medium` | Chunk-based sorting with about `sqrt(n)` chunks | `O(n sqrt(n))` |
| `--complex` | Turk-style cost-based insertion | see note below |
| `--adaptive` | Selects an internal strategy from the disorder value | mixed |

If no strategy selector is provided, `--adaptive` is used by default.

The subject requires the binary to embed Simple `O(n^2)`, Medium `O(n sqrt(n))`, Complex `O(n log n)`, and Adaptive strategies. The current `--complex` implementation is a Turk-style practical strategy. It is useful for reducing moves on many inputs, but its worst-case operation upper bound is not a strict `O(n log n)` proof. For strict subject compliance, the complex strategy should be replaced or reinforced with a true `O(n log n)` Push_swap operation model algorithm such as radix sort or a stack-based merge strategy.

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

### Disorder Metric

Disorder measures how far the initial stack is from being sorted. It is computed before any move is performed.

For every pair `(i, j)` where `i < j`, the pair is counted as a mistake when `a[i] > a[j]`. The final disorder is:

```txt
mistakes / total_pairs
```

The value is between `0` and `1`:

- `0`: already sorted.
- `1`: worst possible order.
- Between `0` and `1`: partially sorted.

### Algorithm Details

#### Simple: Selection-style min extraction

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

#### Medium: Chunk-based sorting

`--medium` divides normalized indexes into about `sqrt(n)` chunks.

Flow:

1. Normalize values into indexes.
2. Compute `chunk_count = sqrt(n)`.
3. Push each index range from `a` to `b`.
4. Push values back from `b` to `a` in descending index order, rotating `b` in the shorter direction before each `pa`.

Operation model:

- The number of chunks is about `sqrt(n)`.
- Each chunk scan may rotate through stack `a`.
- Rebuilding stack `a` from `b` searches for the next target index and rotates toward it.
- Intended upper bound: `O(n sqrt(n))` Push_swap operations for the chunk-selection phase.
- Extra memory: `O(1)` apart from existing stack nodes.

#### Complex: Turk-style cost-based insertion

`--complex` uses a Turk-style method:

1. Push elements from `a` to `b` until a small base remains.
2. Sort the base case in `a`.
3. For each node in `b`, calculate:
   - its current position in `b`,
   - its target position in `a`,
   - the rotation cost for both stacks.
4. Choose the cheapest node to move.
5. Use combined rotations (`rr` / `rrr`) when both stacks move in the same direction.
6. Push the node back to `a`.
7. Rotate the minimum index to the top.

This strategy is practical and often produces fewer moves than the simple strategy. However, because it repeatedly scans candidates and can rotate up to `O(n)` per insertion, the current worst-case Push_swap operation bound should be considered closer to `O(n^2)` than a proven `O(n log n)`.

#### Adaptive

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
[bench] strategy:   Adaptive / O(n sqrt(n))
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

### Resources

- 42 subject: `pushswap.pdf`.
- Donald Knuth, *The Art of Computer Programming*, for algorithmic analysis background.
- Wikipedia: Big O notation.
- Wikipedia: Sorting algorithm.
- Visual/manual tests using the provided checker.
- AI usage: AI was used to discuss parsing edge cases, operation-count reasoning, README wording, benchmark-mode design, and code review questions. Generated suggestions were reviewed and adapted manually; final responsibility for the implementation remains with the contributors.

---

## 日本語

### 概要

`push_swap` は、2つのスタック `a` / `b` と限られた命令だけを使って整数列を昇順に並べる 42 のグループ課題である。プログラムは重複のない整数列を受け取り、初期スタック `a` を作成し、最終的に `a` が昇順、`b` が空になるような Push_swap 命令列を標準出力へ出力する。

この課題の目的は、正しくソートするだけではなく、出力する操作数をできるだけ少なくすることである。このリポジトリでは、実行時の戦略選択と、subject で要求される任意のベンチマークモードにも対応している。

### 貢献者

- `tsito`: パース、バリデーション、スタック初期化、操作関数の統合、Turk-style ソート、ベンチマークモード、ビルド設定。
- `ksaotome`: チャンクソート、スタックユーティリティ、小規模ソート関連、戦略改善、アルゴリズムレビュー。

評価時には、両者がプロジェクト全体を説明できる必要がある。

### 使い方

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
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_Mac $ARG
```

ベンチマークモード:

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_Mac $ARG
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
| `--medium` | 約 `sqrt(n)` 個のチャンクを使うチャンクソート | `O(n sqrt(n))` |
| `--complex` | Turk-style のコストベース挿入 | 下記注記参照 |
| `--adaptive` | disorder に応じて内部戦略を選択 | 複合 |

戦略指定がない場合は `--adaptive` がデフォルトである。

subject は、Simple `O(n^2)`, Medium `O(n sqrt(n))`, Complex `O(n log n)`, Adaptive の4戦略をバイナリに含めることを要求している。現在の `--complex` は Turk-style の実用的な戦略である。多くの入力で操作数削減に役立つが、最悪ケースの Push_swap 操作数について厳密な `O(n log n)` 証明がある実装ではない。subject に厳密に合わせるには、radix sort やスタックベース merge など、Push_swap 操作数モデルで `O(n log n)` と説明できる戦略へ置き換える、または補強する必要がある。

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

### Disorder 指標

disorder は、初期スタックがどれだけソート済み状態から離れているかを表す。命令を1つも実行する前に計算する。

すべてのペア `(i, j)` について `i < j` かつ `a[i] > a[j]` のとき、そのペアを mistake として数える。

```txt
mistakes / total_pairs
```

値は `0` から `1` である。

- `0`: すでにソート済み。
- `1`: 最悪の並び。
- `0` と `1` の間: 一部は整っているが乱れている。

### アルゴリズム詳細

#### Simple: 選択ソート風の最小値抽出

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

#### Medium: チャンクソート

`--medium` は、正規化済み index を約 `sqrt(n)` 個のチャンクに分ける。

流れ:

1. 値を index に正規化する。
2. `chunk_count = sqrt(n)` を計算する。
3. 各 index 範囲を `a` から `b` へ push する。
4. `b` から降順 index で値を探し、短い方向に回転してから `pa` で `a` に戻す。

操作数モデル:

- チャンク数は約 `sqrt(n)` である。
- 各チャンクの探索で `a` を回転する。
- `b` から戻すときは対象 index を探して短い方向へ回転する。
- チャンク選択部分の意図した上界は `O(n sqrt(n))` Push_swap 操作である。
- 追加メモリは、既存のスタックノードを除けば `O(1)` である。

#### Complex: Turk-style コストベース挿入

`--complex` は Turk-style の手法を使う。

1. 小さな基底ケースが残るまで `a` から `b` へ push する。
2. `a` の基底ケースをソートする。
3. `b` の各ノードについて、現在位置、`a` での target position、両スタックの回転コストを計算する。
4. 最も安いノードを選ぶ。
5. 同じ方向へ回転できる場合は `rr` / `rrr` を使う。
6. `pa` で `a` へ戻す。
7. 最後に最小 index を top へ回転する。

この戦略は実用的で、単純戦略より操作数を減らせることが多い。ただし、候補の走査と挿入時の回転を繰り返すため、現在の実装の最悪ケースの Push_swap 操作数は、厳密な `O(n log n)` ではなく `O(n^2)` に近い上界として扱うべきである。

#### Adaptive

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
[bench] strategy:   Adaptive / O(n sqrt(n))
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

### 参考資料

- 42 subject: `pushswap.pdf`
- Donald Knuth, *The Art of Computer Programming*: アルゴリズム解析の基礎。
- Wikipedia: Big O notation.
- Wikipedia: Sorting algorithm.
- 提供 checker を使った手動テスト。
- AI 利用: パースの境界ケース、操作数の考え方、README の構成、ベンチマークモード設計、コードレビュー観点の相談に使用した。生成された提案は手動で確認・修正しており、最終的な実装責任は貢献者にある。
