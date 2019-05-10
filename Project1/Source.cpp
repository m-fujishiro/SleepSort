/**
 *スリープソート
 */
#include <iostream>
#include <thread>
#include <vector>
#include <process.h>
#include <windows.h>
using namespace std;

void sleepSort(int);

int main() {
	//ソート元配列
	int arr[] = { 1,3,4,6,2,2,5,6,5,2 };
	//ループで回すためにvector配列を作る
	vector<thread> th;
	//引数に関数を入れることで並列処理ができる 
	for (int i : arr) th.push_back(thread(sleepSort, i));	
	//joinしなければいけない
	for (int i = 0; i < th.size(); i++) th[i].join();
	cout << endl;
	system("pause");
}

void sleepSort(int i) {
	//このくらいなら一応安全性がほんの少しマシ？
	this_thread::sleep_for(std::chrono::microseconds(i*10000));
	cout << i << endl;
}


