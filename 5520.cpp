/*5520번 The Clocks(C++11)*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <utility>

using namespace std;

string clocks;
set<string> vst;
queue<pair<pair<string, int> , string> > Q; //{{map, cnt}, path}

void Rotate(int i)
{
	clocks[i] = '0'+(clocks[i]-'0'+1)%4;
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	int i,j;
	char tmp;
	for(i = 0; i < 9; i++){
		cin>>tmp;
		clocks += tmp;
	}

	//	cout<<"clocks :"<< clocks <<endl; //debug
	Q.push( { {clocks, 0} , "1"} );
	while(!Q.empty())
	{
		string cur = Q.front().first.first;
		int ccnt = Q.front().first.second;
		string path = Q.front().second;
		Q.pop();

		if(!cur.compare("000000000")){
			//	cout<<ccnt<<endl; //debug
			for(i = 1; i < path.length(); i++)
				cout<< path[i] <<" ";
			cout<<endl;
			return 0;
		}
		vst.insert(cur);
		
		//cout<<path.back()<<endl;//debug

		/*1->2->3 이나 1->3->2나 동일한 결과이므로 제일 마지막에 쓴 번호 이상의 번호 만 탐색을 돌게 한다(안했더니 메모리 초과 남)*/
		switch(path.back())
		{
			case '1':
			clocks = cur;
			Rotate(0);
			Rotate(1);
			Rotate(3);
			Rotate(4);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'1'} );

			case '2':
			clocks = cur;
			Rotate(0);
			Rotate(1);
			Rotate(2);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'2'} );

			case '3':
			clocks = cur;
			Rotate(1);
			Rotate(2);
			Rotate(4);
			Rotate(5);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'3'} );

			case '4':
			clocks = cur;
			Rotate(0);
			Rotate(3);
			Rotate(6);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'4'} );

			case '5':
			clocks = cur;
			Rotate(1);
			Rotate(3);
			Rotate(4);
			Rotate(5);
			Rotate(7);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'5'} );

			case '6':
			clocks = cur;
			Rotate(2);
			Rotate(5);
			Rotate(8);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'6'} );

			case '7':
			clocks = cur;
			Rotate(3);
			Rotate(4);
			Rotate(6);
			Rotate(7);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'7'} );

			case '8':
			clocks = cur;
			Rotate(6);
			Rotate(7);
			Rotate(8);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'8'} );

			case '9':
			clocks = cur;
			Rotate(4);
			Rotate(5);
			Rotate(7);
			Rotate(8);
			if(vst.find(clocks) == vst.end())
				Q.push( {{clocks, ccnt+1}, path+'9'} );
		}
	}
	return 0;
}
