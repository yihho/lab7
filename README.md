# lab3
A
定義class Cow在cow.cpp和標頭檔cow.h中。
Cow includes
  member data:num, weight, total(用來存前五中的牛的重量總和), vector <int> cow_weight(用來存取所有牛隻的重量)
  member function:top_five_total(int num, vector <int> cow_weight)用來讀取所有牛隻的重量，並使用sort()將所有重量依升冪排序，取得最重的五隻並加總其體重。
  
main function中讀取檔案，將檔案存到class Cow中，並使用Cow的member function去算出最重五隻牛的體重總和。


B
1000
sort(): 0 seconds
v1/v2 are different.
insertion_sort(): 0.01 seconds
v1/v2 are the same.

10000
sort(): 0 seconds
v1/v2 are different.
insertion_sort(): 1.28 seconds
v1/v2 are the same.

100000
sort(): 0.04 seconds
v1/v2 are different.
insertion_sort(): 128.21 seconds
v1/v2 are the same.

1000000
sort(): 0.49 seconds
v1/v2 are different.


sort():O(nlogn)
insertion_sort():O(n2)


