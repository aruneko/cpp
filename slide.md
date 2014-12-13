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

### Better Cってなんぞ？
* 要するに "C++ without Class"
	* (でもちょっとだけ触れます。ごめんなさい)

--

### いろんなコーディングスタイル
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

## 

--

## ちょっとだけ名前空間の話
* 人が作った関数や変数名が衝突しないように設定します
* C++の標準関数等はstd名前空間に所属しています
  * 例えばiostreamに入っている関数など
* デフォルトで使いたい名前空間を指定するときは「`using namespace hoge;`」を使います
  * (ただしデフォルト名前空間を指定すると名前空間の存在意義が...)

--

## じゃぁ標準入出力の話を

--

## 川の流れのように
* C++での入出力は「stream」を使います
* 入力側から出力側へ流れています
* `<<`とか`>>`とかで流す向きを決めます
  * `<<`を挿入子、`>>`を抽出子といいます
* 流れの始点(入力)は`cin`を、終点(出力)は`cout`を使います
  * 出力の終わりに`endl`を使うと改行までやってくれます

--

## 標準出力のサンプルコード(再掲)

```cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Hello World" << endl;	
}
```
--

## 細かい補足(1)
* `#include <iostream>`
	* iostreamの読み込みを意味しています
	* iostreamには入出力ストリームに関わる定義が書かれています
		* Unix系OSの場合"/usr/include/c++/VERSION/iostream"に存在します
* `using namespace std;`
	* デフォルト名前空間stdの使用を宣言しています

--

## 細かい補足(2)
* coutのあとに挿入子をつけてダブルクオーテーションで囲った文字列を接続すると、その文字列が標準出力(ターミナルだったり、テキストファイルだったり)に出力されます
* endlの代わりに文字列の終わりに'\n'を使っても改行できます
  * `cout << "hoge\n";`って感じに！
* 文の終わりはセミコロンを使います
  * 普段Rubyとか書いている人、要注意です

--

## 標準入力のサンプルコード

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "整数を入力してください：";
  cin >> n;
  cout << n << endl;
}
```

--

## 細かい補足（1）
* `int n;`
  * int型の変数nを宣言しています
  * 型については後述します
  * intは整数型ですよ！
* coutを改行しないで使いたいときは文字列の後いきなりセミコロンでぶった切ります

--

## 細かい補足（2）

* cinには抽出子、coutには挿入子を使います
* coutにはいきなり整数を挿入することができます
  * もちろん、演算(+ - * /など)もできますよ

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

---

# 反復処理

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
