#include <iostream>
#include <vector>
using namespace std;
class txt
{
public:
 txt(vector<char> cha){ch = cha;}
 void count_word(); //ͳ�Ƶ�����
 void count_line(); //ͳ������
 void count_ch(); //ͳ���ַ���
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
 cout << "��������" << count <<endl;
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
 cout << "��������" << count <<endl;
}
void txt::count_ch()
{
 int count = 0;
 for (int i=0;i < ch.size();i++)
 {
  if ('\012' != ch[i])
   count++;
 }
 cout << "�ַ�����" << count <<endl;
}
int main()
{
 vector<char> words;
 cout << "����������ı������н�����" <<endl;
 char word;
 //�����ı��������Կո�ͻ���
 cin.unsetf( ios::skipws );
 while (cin >> word )
 {
  //�ж��������������֣��򷵻�
  if (word >= '0' && word <= '9')
  {
   cout << "�Բ�����������ַ��к����֡�" << endl;
   return -1;
  }
  words.push_back(word);
  int i = words.size();
  if (words[i-2] == '\012' && words[i-1] == '\012')
  {
   break;
  }
 }
 //ɾ�����һ������,����д������
 words.pop_back();
 //���������
 txt t(words);
 t.count_line();
 t.count_word();
 t.count_ch();
 return 0;
}