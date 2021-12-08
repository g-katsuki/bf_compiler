# Brainfuckコンパイラ速度対決
--------------------------

Last update: 2021.12.07

# Brainfuckとは
https://qiita.com/TomoShiozawa/items/25dcce1540085df71053

# ルール
* 各自, 好きな言語でBrainfuckコンパイラを実装する
* ビルド手順と実行方法を記したREADMEを用意する
* コンパイラが完成したらREADMEとソース一式を飯塚まで送る
* 飯塚環境で時間計測

# 環境
* Ubuntu20.04環境でaptで構築できる環境ならなんでもOK

# テスト
作成したコンパイラが正しく実装されているか`examples`以下のコードで動作確認する.

## hello.bf

実行結果
```txt
$ python sample.py examples/hello.bf
Hello World!
```

## traiangle.bf

実行結果
```txt
$ python sample.py examples/triangle.bf
                                *
                               * *
                              *   *
                             * * * *
                            *       *
                           * *     * *
                          *   *   *   *
                         * * * * * * * *
                        *               *
                       * *             * *
                      *   *           *   *
                     * * * *         * * * *
                    *       *       *       *
                   * *     * *     * *     * *
                  *   *   *   *   *   *   *   *
                 * * * * * * * * * * * * * * * *
                *                               *
               * *                             * *
              *   *                           *   *
             * * * *                         * * * *
            *       *                       *       *
           * *     * *                     * *     * *
          *   *   *   *                   *   *   *   *
         * * * * * * * *                 * * * * * * * *
        *               *               *               *
       * *             * *             * *             * *
      *   *           *   *           *   *           *   *
     * * * *         * * * *         * * * *         * * * *
    *       *       *       *       *       *       *       *
   * *     * *     * *     * *     * *     * *     * *     * *
  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
```

## bench-2.bf

実行結果
```
$ python sample.py examples/bench-2.bf
ZYXWVUTSRQPONMLKJIHGFEDCBA
```

## mandelbrot-tiny.bf

実行結果
```txt
$ python sample.py examples/mandelbrot-tiny.bf
AAAAAAAABBBBBBBBCCCCCCCCCCCCCCCCCCDDDDEFEEDDDCCCCCBBBBBBBBBBBBBBB
AAAAAAABBBBBBCCCCCCCCCCCCCCCCCDDDDDDEEFIKGGGDDDDDCCCCBBBBBBBBBBBB
AAAAAABBBBCCCCCCCCCCCCCCCCCDDDDDDDEEEFGHKPIGFEDDDDDCCCCCBBBBBBBBB
AAAAABBBCCCCCCCCCCCCCCCCCDDDDDDDEEEFGPVT  Q[HEEEEDDDCCCCCCBBBBBBB
AAAABBCCCCCCCCCCCCCCCCDDDDDDDEEFFFGGHK      HGFFEEEDDDCCCCCBBBBBB
AAABBCCCCCCCCCCCCCCCDDDDDEEEFGK MJJ NR    YS L HHGIJFDDCCCCCCBBBB
AAABCCCCCCCCCCCCCDDDEEEEEEFFFHI                    MGEDDCCCCCCBBB
AABCCCCCCCCCCCDDEEEEEEEEFFFGY Q                   MHGEEDCCCCCCCBB
AACCCCCCDDDDDEEFLHGGHMHGGGHIR                      QLHEDDCCCCCCCB
ABCCDDDDDDEEEEFGIKU    RLJJL                        IFEDDCCCCCCCB
ACDDDDDDEEEEEGGHOS        QR                        JFEDDDCCCCCCC
ADDDDDEFFFGGHKOPS                                   GEEDDDCCCCCCC
A                                                PJGFEEDDDCCCCCCC
ADDDDDEFFFGGHKOPS                                   GEEDDDCCCCCCC
ACDDDDDDEEEEEGGHOS        QR                        JFEDDDCCCCCCC
ABCCDDDDDDEEEEFGIKU    RLJJL                        IFEDDCCCCCCCB
AACCCCCCDDDDDEEFLHGGHMHGGGHIR                      QLHEDDCCCCCCCB
AABCCCCCCCCCCCDDEEEEEEEEFFFGY Q                   MHGEEDCCCCCCCBB
AAABCCCCCCCCCCCCCDDDEEEEEEFFFHI                    MGEDDCCCCCCBBB
AAABBCCCCCCCCCCCCCCCDDDDDEEEFGK MJJ NR    YS L HHGIJFDDCCCCCCBBBB
AAAABBCCCCCCCCCCCCCCCCDDDDDDDEEFFFGGHK      HGFFEEEDDDCCCCCBBBBBB
AAAAABBBCCCCCCCCCCCCCCCCCDDDDDDDEEEFGPVT  Q[HEEEEDDDCCCCCCBBBBBBB
AAAAAABBBBCCCCCCCCCCCCCCCCCDDDDDDDEEEFGHKPIGFEDDDDDCCCCCBBBBBBBBB
AAAAAAABBBBBBCCCCCCCCCCCCCCCCCDDDDDDEEFIKGGGDDDDDCCCCBBBBBBBBBBBB
```

# 速度計測
* 以下のサンプルコードの実行時間を`time`コマンドで計測し, 合計時間で勝敗を決める
  * `bench-2.bf`
  * `mandelbrot-tiny.bf`

# スケジュール
* 2022/1/4
  * 中間結果発表
* 2021/2/1
  * 最終結果発表
