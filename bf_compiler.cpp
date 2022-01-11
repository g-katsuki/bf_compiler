#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;
using std::cout;

/*****************************************************************
* 与えられた行に対して, map型にインデックスと記号を格納する関数
******************************************************************/
void getSymbols(const string &line, map<int, char> &symbols, int &idx, int &comma, int &space)
{
  /*** '+'以外の記号を格納してその間を'+'と考える. スペースはカウントしておいて格納時に引く ***/
  int count = 0;
  for(int i = 0, size = line.size(); i < size; i++){
    if(line[i] == ' ') space++;
    else if(line[i] != '+'){
      symbols[i+idx-space] = line[i];
    }
    if(line[i] == '.') comma++;
    count++;
  }
  idx += count;
  // std::cout << line << std::endl;
}

/****************************************************************
* mapのインデックスと記号に対しての操作を行う関数
*****************************************************************/
void calcSymbols(const map<int, char> &symbols)
{
  int roop_count = 0, count_idx = 0, past_symbol_idx = 0, size_count = 1;
  vector<int> counts(1);
  stack<int> roop_idx_stack;
  stack<int> roop_place_stack;
  auto roop_it = symbols.begin();

  int dot_count_for_debug = 0;
  for(auto it = symbols.begin(); it != symbols.end(); it++){
    if(it == symbols.end()) cout << "END" << endl;
    counts[count_idx] += it->first - past_symbol_idx - 1;
    past_symbol_idx = it->first;
    if(it->second == '>'){
      /*** カウントするインデックスを+1 ***/
      count_idx++;
      if(size_count < count_idx + 1) counts.push_back(0);
      continue;
    }
    else if(it->second == '<'){
      /*** カウントするインデックスを-1 ***/
      count_idx--;
      continue;
    }
    else if(it->second == '-'){
      /*** 現在のカウントを-1 ***/
      counts[count_idx]--;
      continue;
    }
    else if(it->second == '['){
      /*** 現在の場所をスタックにpush ***/
      roop_place_stack.push(it->first);
      continue;
    }
    else if(it->second == ']'){
      if(counts[count_idx] > 0){
        /*** 現在のカウントが0より大きければスタックの位置に戻る ***/
        it = symbols.find(roop_place_stack.top());
        past_symbol_idx = it->first;
      } else {
        /*** 現在のカウントが0以下ならスタックをpop ***/
        roop_place_stack.pop();
      }
      continue;
    }
    else if(it->second == '.'){
      /*** 出力 ***/
      printf("%c", counts[count_idx]);
    }
  }
}

int main(int argc, char **argv)
{
  std::ifstream file;
  std::string file_name = argv[1];
  std::string path = "./../sample/examples/" + file_name;
  file.open(path, std::ios::in);
  int *ptr;
  int idx = 1, comma = 0, space = 0;
  map<int, char> symbols;
  std::string line;
  
  while(std::getline(file, line)){
    getSymbols(line, symbols, idx, comma, space);
  }

  calcSymbols(symbols);

  return 0;
}