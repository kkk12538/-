#include<iostream>
#include<fstream>
using namespace std;
struct Vex{
	int num;		//������ 
	string name;		//�������� 
	string desc;	//������� 
}; 
struct Edge{
	int vex1;
	int vex2;
	int weight;
};
struct Dis{
	bool visited=false;
	int value=0;
	string path="";
}; 
Vex m_aVexs[20];
Edge m_aEdge[10];
int m_AdjMaxtrix[20][20];
Dis dis[7];
void createGraph();
void Dijkstra(int begin,int end);
void FindShortPath();

int main(){
	createGraph();
	FindShortPath();
	return 0;
}



void createGraph(){
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			m_AdjMaxtrix[i][j]=INT_MAX;
		}
	}
	ifstream file,file1;
	string count;
	file.open("vex.txt",ios::in);
	file>>count;
    for(int i=0;i<7;i++){
    	if(file.eof())
    		break;
        file>>m_aVexs[i].num>>m_aVexs[i].name>>m_aVexs[i].desc;
    } 	
	file.close();
	file1.open("edge.txt",ios::in);
	for(int i=0;i<10;i++){
    	if(file1.eof())
    		break;
        file1>>m_aEdge[i].vex1>>m_aEdge[i].vex2>>m_aEdge[i].weight;
        m_AdjMaxtrix[m_aEdge[i].vex1][m_aEdge[i].vex2]=m_aEdge[i].weight;
    	m_AdjMaxtrix[m_aEdge[i].vex2][m_aEdge[i].vex1]=m_aEdge[i].weight;
	} 
	
	cout<<"==== ������������ͼ ===="<<endl;
	cout<<"�������:"<<count<<endl;
	cout<<"---- ���� ----"<<endl;
	for(int i=0;i<7;i++){
       cout<<m_aVexs[i].num<<"-"<<m_aVexs[i].name<<endl;
	} 
	cout<<"---- �� ----"<<endl; 
	for(int i=0;i<10;i++){
    	cout<<"<"<<m_aEdge[i].vex1<<","<<m_aEdge[i].vex2<<"> "<<m_aEdge[i].weight<<endl; 
    } 
    file1.close();
}
void FindShortPath(){
	int begin,end;
	cout<<"==== �������·�� ===="<<endl;
	for(int i=0;i<7;i++){
		cout<<m_aVexs[i].num<<"-"<<m_aVexs[i].name<<endl;
	} 
	cout<<"���������ı�ţ�";
	cin>>begin;
	cout<<"�������յ�ı�ţ�";
	cin>>end;
	Dijkstra(begin,end);
	 
}
void Dijkstra(int begin,int end){
	for(int i=0;i<7;i++){			//��ʼ��dis 
		dis[i].path=m_aVexs[begin].name+"->"+m_aVexs[i].name;
		dis[i].value=m_AdjMaxtrix[begin][i];
		dis[i].visited=false; 
	}
	dis[begin].value=0;
	dis[begin].visited=true;	
	for(int i=0;i<6;i++){		
		int temp;
		int min=INT_MAX;
		for(int j=0;j<7;j++){
			if(!dis[j].visited&&dis[j].value<min){
				min=dis[j].value;
				temp=j;	
			}
		}
		dis[temp].visited=true;
		for(int j=0;j<7;j++){
			if(!dis[j].visited&&m_AdjMaxtrix[temp][j]!=INT_MAX&&(dis[temp].value+m_AdjMaxtrix[temp][j])<dis[j].value){
				dis[j].value=dis[temp].value+m_AdjMaxtrix[temp][j];
				dis[j].path=dis[temp].path+"->"+m_aVexs[j].name;
			}			
		}
	}
	for(int i=0;i<7;i++){
		if(i==begin)
			continue;
		if(dis[i].path.substr(dis[i].path.length()-3,dis[i].path.length()-1)==m_aVexs[end].name){
			cout<<"���·��Ϊ��"<<dis[i].path<<endl;
			cout<<"��̾��룺"<<dis[i].value<<endl; 
		}
			
	} 
} 

