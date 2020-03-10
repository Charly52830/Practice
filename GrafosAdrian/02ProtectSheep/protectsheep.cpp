#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int main(){
	int r,c;
	scanf("%d %d",&r,&c);
	char terreno[r][c];
	for(int curRow = 0;curRow < r;curRow++){
		string s;
		cin>>s;
		for(int curCol = 0;curCol < c;curCol++){
			char aux = s.at(curCol);
			terreno[curRow][curCol] = aux;
		}
	}
	
	for(int curRow = 0;curRow<r;curRow++){
		for(int curCol = 0;curCol < c;curCol++){
			if(terreno[curRow][curCol]== 'W'){
				if(curRow>0){
					if(terreno[curRow-1][curCol]=='.'){
						terreno[curRow-1][curCol] = 'D';
					}else if(terreno[curRow-1][curCol]=='S'){
						printf("No");
						return 0;
					}	
				}
				
				if(curCol>0){
					if(terreno[curRow][curCol-1]=='.'){
						terreno[curRow][curCol-1] = 'D';
					}else if(terreno[curRow][curCol-1]=='S'){
						printf("No");
						return 0;
					}
				}
				
				if(curCol<c-1){
					if(terreno[curRow][curCol+1]=='.'){
						terreno[curRow][curCol+1] = 'D';
					}else if(terreno[curRow][curCol+1]=='S'){
						printf("No");
						return 0;
					}
				}
				
				if(curRow<r-1){
					if(terreno[curRow+1][curCol]=='.'){
						terreno[curRow+1][curCol] = 'D';
					}else if(terreno[curRow+1][curCol]=='S'){
						printf("No");
						return 0;
					}
				}
			}
		}		
	}
	
	printf("Yes\n");
	for(int curRow = 0;curRow < r;curRow++){
		for(int curCol = 0;curCol < c;curCol++){
			printf("%c",terreno[curRow][curCol]);
		}
		printf("\n");
	}
	
	
	return 0;
}
