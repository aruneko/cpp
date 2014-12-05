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
```c:hello.c
#include <stdio.h>

int main(void) {
	printf("Hello World¥n");
	return 0;
}
```

--

## かなりCっぽいC++

```c++:hello.cpp
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

```c++:hello.cpp
# include <iostream>
using namespace std;

int main() {
	cout << "Hello World" << endl;
	// なんか知らない書き方出てきたんですが
}
```

--

## (おまけ) 原理主義者

```c++:hello.cpp
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

## ちょっとだけ名前空間の話
* 人が作った関数や変数名が衝突しないように設定します
* C++の標準関数等はstd名前空間に所属しています
  * 例えばiostreamに入っている関数など
* 使いたい名前空間を指定するときは「using namespace」を使います

--

## じゃぁ標準出力の話を

--

## 川の流れのように
* C++での入出力は「stream」を使います
* 入力側から出力側へ流れています
* `<<`とか`>>`とかで流す向きを決めます
* 流れの始点は`cin`、終点は`cout`です

--

## 標準出力のサンプルコード(再掲)

```c++:hello.cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Hello World" << endl;	
}
```

--

## 細かい補足
* `#include <iostream>`
	* iostreamの読み込みを意味しています
	* iostreamには入出力ストリームに関わる定義が書かれています
		* Unix系OSの場合"/usr/include/c++/VERSION/iostream"に存在します
* `using namespace std;`
	* 名前空間stdの使用を宣言しています
		* 関数や変数の名前が衝突しないように用います
--

## 

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
