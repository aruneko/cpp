# CPP
## /＊ぺあぷろ！＊/
### 〜 Better C講座 〜

---

# 本日のメニュー

--

* はじめに
* 標準入出力
* 条件分岐
* 反復処理
* 型
* 配列
* 関数
* ポインタ
* 文字列
* STL
* Class

---

# はじめに

--

## 基本的なスタンス
* 主にANSI Cとの違いに主眼を置いて解説します

--

## Better Cってなんぞ？
* 要するに "C++ without Class"
  * (でもちょっとだけ触れます。ごめんなさい)

--

## いろんなコーディングスタイル
* 一口にC++と言ってもいろんな書き方があるのでちょっと見比べてみよう
  * 今回はおなじみHello Worldでやってみる
  * 詳しい説明は後でするので、とりあえずスタイルの違いだけ見てみます

--

## ふつーのC

```c
#include <stdio.h>

int main(void) {
  printf("Hello World¥n");
  return 0;
}
```

--

## かなりCっぽいC++

```cpp
# include <cstdio>
using namespace std;
// なんか増えてる

// voidどこいった
int main() {
  printf("Hello World¥n");
  // return 0してないんですけど
}
```

--

## Better C (今回はこのスタイル)

```cpp
# include <iostream>
using namespace std;

int main() {
  cout << "Hello World" << endl;
  // なんか知らない書き方出てきたんですが
}
```

--

## (おまけ) 原理主義者

```cpp
# include <iostream>

int main() {
  std::cout << "Hello World" << std::endl;
  // こわい
}
```

--

というわけで、Cとの違いを見ながらBetter Cをやっていきましょうー

---

# 標準入出力

--

## この章でわかるようになるサンプルコード

```cpp
# include <iostream>
using namespace std;

int main() {
  int n;

  cout << "整数を入力してください";
  cin >> n;
  cout << "入力した整数は" << n << "です" << endl;
}
```
じゃ、早速1行目から見ていきましょう

--

```cpp
# include <iostream>
```
* iostreamヘッダの読み込みを意味しています
* iostreamには入出力ストリームの定義が書かれています
  * ちょっと下の方に書いてあった`cout`とか`cin`とか
* Unix系OSの場合"/usr/include/c++/VERSION/iostream"に存在します
* C言語用のヘッダを使いたいときは、先頭にcを付加して最後の.hを取ります
  * 例：`stiod.h` → `cstdio`

--

```cpp
using namespace std;
```
* std名前空間をデフォルトで使用することを宣言しています
* 名前空間は、他人が作った関数・変数名が衝突しないように設定します
* C++の標準関数等はstd名前空間に所属しています
  * 例えばiostreamに入っている`cout`や`cin`など
* ただしデフォルト名前空間を指定すると名前空間の存在意義が無くなります

--

```cpp
int main()
```
* C++では、関数の引数を省略すると自動的にvoid扱いになります
* コマンドライン引数を取りたいときは`int argc, char** argv`を指定しましょう

--

```cpp
int n
```
* int型変数`n`の宣言です
* int型であれば、宣言時に0で初期化されます
* C言語とほぼ変わっていません
  * が、ちょっと違うところもあるので後で専門に扱います

--

```cpp
cout << "整数を入力してください";
```
* 挿入子(`<<`)の右辺にあるものを標準出力に流します
* int型でも、double型でも、文字列でも、何でも流せます
* 文字列の場合はダブルクオーテーションで囲ってください
  * 文字列内ではもちろんエスケープシーケンスも有効です
  * つまり`"hoge\thoge\n"`とかそういうことができます

--

```cpp
cin >> n;
```
* 標準入力から受け取ったものを抽出子(`>>`)の右辺にある変数に入力します
* 入力されたものの型を自動で判断してくれます
  * int型の変数にdouble型の入力を入れると切り捨て処理が行われます
  * 同じく文字(列)を入力すると、入力が捨てられます

--

```cpp
out << ... << endl;
```
* 出力の終わりに`endl`を使うと改行してくれます
* ついでに出力バッファの消去も行います
  * ただし大量に使うとこの処理のせいで重くなるかも

--

## 細かい補足
* 文の終わりはセミコロンを使います
  * 普段Rubyとか書いている人、要注意です
* C言語と違って、main関数に`return 0;`は必要ありません。自動で0を返します
  * ただしエラー時などは自分で適切なreturn処理を入れてください
* coutに数値を入力するとき、いきなり演算(+ - * /など)もできます
  * `cout << a / b << endl;`という感じ

--

## 練習問題
二つの数xとyを読み込んでその和を表示するプログラムを作ってください！

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
  int x, y;
  cout << "整数x：";
  cin >> x;
  cout << "整数y：";
  cin >> y;

  cout << x + y << endl;
}
```

---

# 条件分岐

--

## この章でわかるようになるサンプルコード(1)

```cpp
# include <iostream>
using namespace std;

int main() {
  int x;

  cout << "整数を入力してください：";
  cin >> x;

  if (x > 0) {
    cout << "入力した数は正の数です" << endl;
  } else if (x == 0) {
    cout << "入力した数は0です" << endl;
  } else {
    cout << "入力した数は負の数です" << endl;
  }
}
```

--

## この章でわかるようになるサンプルコード(2)

```cpp
# include <iostream>
using namespace std;

int main() {
  bool t = true;
  bool f = false;

  cout << (t && f) << "\n";
  cout << (t || f) << "\n";
  cout << boolalpha;
  cout << (1 > 2) << "\n";
  cout << (1 <= 4) << "\n";
  cout << (5 == 5) << "\n";
}
```
今回は2つありますが、順番に見ていきましょうー

--

```cpp
if (x > 0) {
  cout << "入力した数は正の数です" << endl;
} else if (x == 0) {
  cout << "入力した数は0です" << endl;
} else {
  cout << "入力した数は負の数です" << endl;
}
```
* おなじみif文はC言語と何も変わりません
* ifもelseもそのままいつも通り使えます

--

```cpp
bool t = true;
bool f = false;
```

* C++にはtrueかfalseかを表すbool型があります
* int型に変換することができ、`false`が`0`、`true`が`1`になります
* 逆にint型から変換すると、`0`が`false`、`0以外`が`true`になります

--

```cpp
(t && f)
(1 > 2)
// などその他
```

* `&&`や`||`などおなじみの論理演算子もCと同様に使えます
* もちろん`>`とか`<=`とかの比較演算子も同様です

--

```cpp
cout << boolalpha;
```

* boolalphaをcoutに挿入すると、それ以降のbool型の表示が`0`や`1`から`false`や`true`になります

--

## 蛇足
* 条件演算子`(条件) ? (trueの式) : (falseの式)`は何ら変わりありません
* switch-case文も何も変わりありません

--

## 練習問題

入力した数が3で割り切れるかどうかを判定するプログラムを作ってください。ただし0以下の数が入力された場合は何らかの形でエラーを返すようにしてください。

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "自然数を入力してください：";
  cin >> n;

  if (n > 0) {
    if (!(n % 3)) {
      cout << n << "は3で割り切れます" << endl;
    } else {
      cout << n << "は3で割り切れません" << endl;
    }
  } else {
    cout << "入力値が不正です" << endl;
  }
}
```

---

# 反復処理

--

## この章でわかるようになるサンプルコード

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  do {
    cout << "自然数を入力してください：";
    cin >> n;
    cin.clear();
    cin.ignore();
  } while (n <= 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << "#";
    }
    cout << endl;
  }
}
```

--

```cpp
do {
  ...
} while (...)
```

* おなじみのdo-while文はCと変わらずそのまま使えます

--

```cpp
for (int i = 0; i < n; i++) {
  ...
}
```

* C++では、ブロック内変数を柔軟に宣言できます
* そのため、for文内だけで有効にしたい変数はその場で宣言できます
  * ただしブロックを抜けると参照できなくなるので要注意
* 特にfor文ではこの形が頻繁に利用されるのでぜひ覚えてください

--

```cpp
cin.clear();
cin.ignore();
```

* 繰り返し文には関係ないですがちょっと説明
* `cin.clear()`は、変な物が入力された場合にcinが立てるエラーフラグを解除します
  * ちゃんと解除しないと立てっぱなしになります
  * つまりこのサンプルの場合永遠に値を入力できなくなります
* `cin.ignore()`は、cinバッファにたまった物を1つずつ消去します
  * きちんと削除しないとバッファにたまったままになります
  * つまり、いつまでたっても次の入力を受け付けられなくなります

--

## 蛇足

* もちろんwhile文もC言語と同様に扱えます
* `continue`文や`break`文も有効に使うといいでしょう
* 多重ループを一気に抜けるなら`goto`文を使うと簡潔です

--

## 練習問題

縦の長さがx、横の長さがyの長方形を\#で描くプログラムを作成してください

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
  int x, y;

  do {
    cout << "自然数x, yを入力してください：";
    cin >> x >> y;
    cin.clear();
    cin.ignore();
  } while (x <= 0 || y <= 0);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cout << "#";
    }
    cout << endl;
  }
}
```

---

# 型

---

# 配列

---

# 関数

---

# ポインタ

---

# 文字列

---

# STL

---

# Class

---

# おしまい
