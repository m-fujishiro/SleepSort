/**
 *�X���[�v�\�[�g
 */
#include <iostream>
#include <thread>
#include <vector>
#include <process.h>
#include <windows.h>
using namespace std;

void sleepSort(int);

int main() {
	//�\�[�g���z��
	int arr[] = { 1,3,4,6,2,2,5,6,5,2 };
	//���[�v�ŉ񂷂��߂�vector�z������
	vector<thread> th;
	//�����Ɋ֐������邱�Ƃŕ��񏈗����ł��� 
	for (int i : arr) th.push_back(thread(sleepSort, i));	
	//join���Ȃ���΂����Ȃ�
	for (int i = 0; i < th.size(); i++) th[i].join();
	cout << endl;
	system("pause");
}

void sleepSort(int i) {
	//���̂��炢�Ȃ�ꉞ���S�����ق�̏����}�V�H
	this_thread::sleep_for(std::chrono::microseconds(i*10000));
	cout << i << endl;
}


