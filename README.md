# HW2-Data_Structure
make完產生arr.o bs.o ll.o bst.o hash.o rand.o a.out

make clean會刪除上述的檔案

-d N：插入的資料筆數，每筆資料是唯一的(1e4, 1e5, 1e6)，執行後會產生dataset.txt，即為建立資料結構的資料集

-q M：查詢資料筆數(1e3, 1e4, 1e5)，執行後會產生targetset.txt，即為查詢目標的資料集

-bst：測量BST建立和查詢所需時間

-bs：測量Binary Search建立資料結構(含 sorting) 和查詢所需時間

-arr：測量array建立資料結構和查詢(linear search)所需時間

-ll：測量linked list建立資料結構和查詢所需時間

-hash：測量hash建立資料結構和查詢所需時間

使用範例：./a.out -d 1e4 -q 1e3 -bst -arr

輸出結果即為選定資料結構的建立時間以及查詢時間

