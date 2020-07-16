# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l5~9: 構造体の配列を宣言

l46: ファイル内の性別の値を宣言したgenderに代入

l47: ファイル内の身長の値を宣言したheightsに代入

l60: ファイル内のIDの値を宣言したIDに代入

l72~88: 入力したIDとファイルから格納したIDを比較して、存在すれば身長と性別を表示する.また,比較したときにIDが違うごとに変数nodata(初期値0)に1ずつ足していく

l90~94: 上記の通りにしていくと、nodataは13または14になる.14になるということは,入力したIDがファイルから格納したIDが一度も一致しなかったということになるので"NO data"と表示する

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```


input the filename of sample height: ../sample/heights.csv
input the filename of sample ID: ../sample/IDs.csv
which ID's data do you want?: 45313002
---
ID :45313002
gender :Male
heights :183.87



input the filename of sample heights:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
which ID's data do you want?: 45313013
-------
NO data
-------


## 修正履歴

