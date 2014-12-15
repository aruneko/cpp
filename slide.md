# CPP
## /＊ぺあぷろ！＊/
### 〜 Better C講座 〜

----

# 本日のメニュー

--

* はじめに
* 標準入出力
* 条件分岐
* 反復処理
* 型
* 配列
* ポインタ
* 関数
* 文字列
* STL
* Class

----

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

----

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
int main();
```

* C++では、関数の引数を省略すると自動的にvoid扱いになります
* コマンドライン引数を取りたいときは`int argc, char** argv`を指定しましょう

--

```cpp
int n;
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
二つの数xとyを読み込んでその和を表示するプログラムを作ってください

### 入力形式
> x y

### 出力形式
> n

### 例
> 1 2  
> 3

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	cout << x + y << endl;
}
```

----

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

### 入力形式
> n

### 出力形式
> ご自由にどうぞ

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;

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

----

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
縦の長さがx、横の長さがyの長方形を\#で描くプログラムを作成してください(AOJ Volume100 - 10012より出題)

### 入力形式
> x y

### 例
> 2 3  
> \#\#\#  
> \#\#\#

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
	int x, y;

	do {
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

----

# 型

--

## この章でわかるようになるサンプルコード

```cpp
#include <iostream>
using namespace std;

int main() {
	int i(5);
	double d(6.9);
	char c('a');

	cout << "変数i = " << i << "; "
		<< "iは" << sizeof(i) << "byteです" << endl;
	cout << "変数d = " << d << "; "
		<< "dは" << sizeof(d) << "byteです" << endl;
	cout << "変数c = " << c << "; "
		<< "cは" << sizeof(c) << "byteです" << endl;

	cout << "i + d = " << i + d << "; "
		<< sizeof(i + d) << "byteです" << endl;
	cout << "i + (int)c = " << i + (int)c << "; "
		<< sizeof(i + (int)c) << "byteです" << endl;
	cout << "i + static_cast<int>(d) = " << i + static_cast<int>(d) << "; "
		<< sizeof(i + static_cast<int>(d)) << "byteです" << endl;
}
```

--

```cpp
int i(5);
double d(6.9);
char c('a');
```

* C++では上記のような方法で変数を初期化することもできます
* どちらかというとクラスのコンストラクタに引数を渡しているイメージ

--

```cpp
sizeof(i)
// など
```

* C言語と同様にsizeof演算子でその型が何byte分か調べることができます

--

```cpp
(int)c
```

* C言語でおなじみのキャスト方法です
* char型→int型ではASCIIコードがその値となります

--

```cpp
static_cast<int>(d)
```

* C++では一枚前の形式に加えて、この方法でもキャストできます
* 暗黙の型変換を明示的に行う際に利用します

--

## (練習問題は)ないです

* ただの確認ですからね()

----

# 配列

--

## この章でわかるようになるサンプルコード

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;

	cout << "自然数を入力してください：";
	cin >> n;

	int x[n];

	for (int i = 0; i < n; i++) {
		x[i] = i;
	}

	for (auto t : x) {
		cout << t << endl;
	}

	cout << endl;

	for (auto &t : x) {
		t += 10; 
	}

	for (auto &t : x) {
		cout << t << endl;
	}
}

```

--

```cpp
int x[n];
```

* C++では、変数を配列の初期化サイズとして用いることができます
* このサンプルでは値をチェックしていませんが、本来はきちんとした値(1以上の整数)が入力されたかどうかチェックすべきです
* この時点で作成された配列は初期化されていないので、確実に初期化処理を書く必要があります

--

```cpp
for (auto t : x) {
	cout << t << endl;
}
```

* 配列の操作についても触れておきたいのでこのお話を
* C++11では"Range-based for"を使うことができます
	* ある配列すべてに何かをしたい場合はとても便利です
	* 書式は`for (一時変数 : 配列)`です
	* ここでは一時変数に`auto t`を使っています
	* 一周するごとに一時変数に`x[i]`の値がコピーされるため、実は効率が悪いです
* autoは、コンパイル時に型を自動で判断する型です
	* 後述しますが、ややこしい型がたくさんあるので使えると便利です
	* ただしどこでも使えるわけではありません。関数の引数や戻り値には設定できません

--

```cpp
for (auto &t : x) {
	t += 10; 
}
```

* 一枚前ではコピーのために効率が悪いと書きました。そこで参照を用います
	* 使い方は簡単、一時変数名の前に`&`をつけるだけ
	* これだけで`t`は一周するごとに`x[i]`の参照になります
	* ここでいう"参照"は"別名(エイリアス)"のような物だと考えてください
	* ただの別名なので、アクセスする先の実体は同一です
		* いちいち値をコピーするような無駄なことはしません
	* ここでは、その性質を利用して値の書き換えを行っています

--

```cpp
for (auto &t : x) {
	cout << t << endl;
}
```

* もちろん、表示も参照を使って行うことができます
* 逐一値をコピーしないので高速です

--

## 蛇足
* n次元配列`x[i][j][k]...`はCと同様です
	* これの操作方法は、先ほどと同様です

--

## 練習問題

n個の入力された数列を逆順に出力するプログラムを作成してください(AOJ Volume100 - 10011より出題)

### 入力形式
> n  
> x1 x2 x3 ... xn

### 出力形式
> xn ... x3 x2 x1
* ただし出力の最後に空白文字を含まないこと

--

## 練習問題(回答例)

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n-1; i > 0; i--) {
		cout << a[i] << " ";
	}
	cout << a[0] << endl;
}
```

----

# ポインタ

--

## この章でわかるようになるサンプルコード

```cpp
#include <iostream>
#include <new>
using namespace std;

int main() {
	int n, *d; 
	cout << "自然数を入力してください：";
	cin >> n;

	try {
		d = new int[n];
	} catch (bad_alloc& e) {
		cout << "オブジェクトの生成に失敗しました\n";
		cout << e.what() << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		*(d + i) = i;
	}

	for (int i = 0; i < n; i++) {
		cout << i[d] << " ";
	}
	cout << endl;

	delete [] d;
}
```

--

```cpp
int *d
```

* Cと同様のintポインタ型変数の宣言です
* メモリ上のあるアドレスを格納することができます
* この場合の"型"はポインタをインクリメントした際、何バイト分進んだアドレスを取得するかを決定します

--

```cpp
d = new int[n];
```

* int型n個分のオブジェクトを動的に生成し、その先頭アドレスをdに代入しています
	* C言語風にcstdlibをincludeしてmallocも使えないこともないです
	* が、こっちの方がシンプルなので活用しましょう

--

```cpp
try {
	...
} catch (bad_alloc& e) {
	...
	cout << e.what() << endl;
	return 1;
}
```

* C++では例外処理を行うtry-catch文が追加されました
* tryのブロックに失敗しそうなことを書きます
	* 今回は配列オブジェクトの生成です
* catchブロックではまず受け取る例外を指定してから失敗時の処理を書きます
	* 今回は例外`bad_alloc`を受け取っています
		* これはメモリ動的確保の失敗を表します
		* `new`ヘッダに定義されているのでincludeが必要です
		* 中身を知りたいときは`what()`メソッドを利用しましょう
	* main関数内でなんか失敗したら`return 1`して終了しましょう

--

```cpp
*(d + i) = i;
```

* `d[i]`はこの式の左辺の糖衣構文です
	* 要するに `d[i] == *(d + i)`
* `*`は間接演算子です。ポインタが指す先の中身を引っ張ってきます
	* このとき、ポインタの"型"によって何バイト分読み込むかを決定します

--

```cpp
cout << i[d] << " ";
```

* 一枚前の続きです
* `*(d + i) == *(i + d) == i[d]`
	* ただ、それだけです

--

```cpp
delete [] d;
```

* オブジェクト配列を破棄するには`delete []`を使います
	* C言語風にcstdlibを読み込んで`free()`を使うこともできます
		* が、newしたものはfreeでは解放できません
	* オブジェクト配列ではなくただのオブジェクトを破棄するなら`delete`のみを使います

--

## (やっぱり)(練習問題は)ないです

* これもただの確認ですからね。後半戦でもたぶん使わないと思いますしおすし()

----

# 関数

----

# 文字列

----

# STL

----

# Class

----

# おしまい
