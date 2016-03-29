#include <iostream>
#include <vector>
using namespace std;
class txt
{
public:
 txt(vector<char> cha){ch = cha;}
 void count_word(); //统计单词数
 void count_line(); //统计行数
 void count_ch(); //统计字符数
private:
 vector<char> ch;
};
void txt::count_line()
{
 int count = 0;
 for (int i=0;i < ch.size();i++)
 {
  if ('\012' == ch[i])
   count++;
 }
 cout << "总行数：" << count <<endl;
}
void txt::count_word()
{
 int count = 0;
 bool v=true;
 for (int i=0;i < ch.size();i++)
 {
  if (!(ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z'))
  {
   if (v)
    count++;
   v=false;
  }
  else
   v=true;
 }
 cout << "单词数：" << count <<endl;
}
void txt::count_ch()
{
 int count = 0;
 for (int i=0;i < ch.size();i++)
 {
  if ('\012' != ch[i])
   count++;
 }
 cout << "字符数：" << count <<endl;
}
int main()
{
 vector<char> words;
 cout << "请输入多行文本，空行结束：" <<endl;
 char word;
 //输入文本，不忽略空格和换行
 cin.unsetf( ios::skipws );
 while (cin >> word )
 {
  //判断如果输入的是数字，则返回
  if (word >= '0' && word <= '9')
  {
   cout << "对不起，您输入的字符中含数字。" << endl;
   return -1;
  }
  words.push_back(word);
  int i = words.size();
  if (words[i-2] == '\012' && words[i-1] == '\012')
  {
   break;
  }
 }
 //删除最后一个空行,因空行代表结束
 words.pop_back();
 //定义类对象
 txt t(words);
 t.count_line();
 t.count_word();
 t.count_ch();
 return 0;
}