/* qunar笔试-象棋马走日
 *
 * 要求：
 * 给定一个8X8的棋盘，和起点、终点位置坐标
 * 问棋子以马走日的方式从起点走到终点最少走多少步？
 *
 * 解决：bfs ,遍历到终点，判断终点坐标所在遍历层数
 *		 即为最少步数
 * */
#include <iostream>
#include <queue>

using namespace std;

struct Pos
{ 
	int x,y;
	Pos(int a, int b): x(a),y(b)  {}
};
bool visited[8][8] = {false};
int cnt = 0;

bool IsValid(const Pos& cur ){ 
	if(cur.x >=0 && cur.x < 8
			&& cur.y >= 0 && cur.y < 8)
		return true;
	return false;
}
void Push(const Pos& p, queue<Pos>& q){ 
	if(IsValid(p) && !visited[p.x][p.y]){ 
		q.push(p); 
		visited[p.x][p.y] = true; 
	}
}
void Bfs(Pos& entry, const Pos& dst ){ 

	queue<Pos> q;
	q.push(entry);
	visited[entry.x][entry.y] = true; 

	while(!q.empty( )){ 
		int num = q.size( );
		++cnt;
		while(num--){ 
			Pos cur = q.front( );
			cout<<cur.x<<","<<cur.y<<" ";
			if(cur.x == dst.x && cur.y == dst.y) return;
			q.pop();

			Pos next(cur.x-2, cur.y+1);  //右上
			Push(next, q);
			next.x = cur.x-1; next.y = cur.y+2;
			Push(next, q);

			next.x = cur.x+1; next.y = cur.y+2;
			Push(next, q);
			next.x = cur.x+2; next.y = cur.y+1;
			Push(next, q);

			next.x = cur.x+2; next.y = cur.y-1;
			Push(next, q);
			next.x = cur.x+1; next.y = cur.y-2;
			Push(next, q);

			next.x = cur.x-1; next.y = cur.y-2;
			Push(next, q);
			next.x = cur.x-2; next.y = cur.y-1;
			Push(next, q);
		} 
		cout<<endl;
	}
}
int main( )
{ 
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	Pos entry(x1, y1), dst(x2, y2);
	Bfs(entry, dst);
	cout<<endl<<"最小步数："<<--cnt<<endl;
	return 0;
} 
