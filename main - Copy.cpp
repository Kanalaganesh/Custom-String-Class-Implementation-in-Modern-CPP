#include<iostream>
#include<string.h>
using namespace std;

class String
{
	char *p;
	public:

	String(){
		//	cout<<"default constructor\n";
		p=new char[100];
	}

	String(const char *t)
	{
		//cout<<"parametrized constructor\n";
		p=new char[strlen(t+1)];
		strcpy(p,t);

	}

	String(String &t)
	{
		//cout<<"copy constructor\n";
		p=new char[strlen(t.p+1)];
		strcpy(p,t.p);
	}

	~String()
	{
		//	cout<<"Destructor\n";
	}

	String operator = (String t)
	{
		cout<<"assignment overloaded\n";
		strcpy(p,t.p);
		return p;

	}


	String operator + (String t)
	{
		cout<<"+ operator\n";
		int i=0,j=0;
		for(i=0;p[i];i++);

		for(j=0;t.p[j];j++)
		  p[i++]=t.p[j];

		p[i]='\0';

		return p;

	}

	char & operator [](int i)
	{
		return p[i];

	} 

	bool operator > (String t)
	{
		cout<<"> operator\n";
		if(strcmp(p,t.p)>0)
			return true;
			else
				return false;
	}

		
	bool operator < (String t)
	{
		cout<<"< operator\n";
		if(strcmp(p,t.p)<0)
			return true;
			else
				return false;
        }


	bool operator >= (String t)
	{
		cout<<">= operator\n";
		if(strcmp(p,t.p)>0||(strcmp(p,t.p)==0))
			return true;
			else
				return false;
        }

	bool operator <= (String t)
	{
		cout<<"<= operator\n";
		if(strcmp(p,t.p)<0||(strcmp(p,t.p)==0))
			return true;
			else
				return false;
        }

	bool operator == (String t)
	{
		cout<<"== operator\n";
		if(strcmp(p,t.p)==0)
			return true;
			else
				return false;
        }

	
	bool operator != (String t)
	{
		cout<<"> operator\n";
		if(strcmp(p,t.p)!=0)
			return true;
			else
				return false;
        }

	void getstring()
	{
		cout<<p<<endl;
	}


 friend istream & operator >>(istream &,String &);
 friend ostream & operator <<(ostream &,String);

 friend void my_strcpy(String &s1,String s2);
 friend void my_strncpy(String &s1,String s2,int n);
 friend int my_strcmp(String s1,String s2);
 friend int my_strncmp(String s1,String s2,int n);
 friend void strcat(String &s1,String s2);
 friend void strcat(String &s1,String s2,int n);
 friend void my_strrev(String &s);
 friend void my_strupper(String &s);
 friend void my_strlower(String &s);
 friend char * my_strchr(String S,char ch);
 friend char * my_strrchr(String s,char ch);
 friend char * my_strstr(String s1,String s2);
 friend int my_strlen(String s);

};

int main()		
{
String s,s1,s2,s3(s2);
char ch,*p;
int op,n,i,a;

while(1)
{
cout<<"enter your choice\n";
cout<<"1)strcpy 2)strncpy  3)strcmp  4)strncmp  5)strcat  6)strncat  7)strrev  8)strupper  9)strlower  10)strchr  11)strrchr  12)strstr  13)strlen 14)exit"<<endl;
cin>>op;

switch(op)
{
case 1:cout<<"enter a string\n";
       cin>>s2;
       my_strcpy(s1,s2);
       cout<<-s1<<endl;
       break;

case 2:cout<<"enter a string\n";
       cin>>s2;
       cout<<"enter a n number of char copy"<<endl;
       cin>>n;
       my_strncpy(s1,s2,n);
       cout<<s1<<endl;
       break;

case 3:cout<<"enter string1 and string 2\n";
       cin>>s1>>s2;
       n=my_strcmp(s1,s2);
       if(n==0)
       cout<<"equal\n";
       else if(n>0)
       cout<<"first string is greater than second string\n";
       else 
       cout<<"second string is greater than first string\n";
       break;
      
case 4:cout<<"enter string1 and string 2\n";
       cin>>s1>>s2;
       cout<<"enter a n number of char compare"<<endl;
       cin>>i;
       n=my_strncmp(s1,s2,i);
       if(n==0)
       cout<<"equal\n";
       else if(n>0)
       cout<<"first string is greater than second string\n";
       else 
       cout<<"second string is greater than first string\n";
       break;


case 5:cout<<"enter string1 and string 2\n";
       cin>>s1>>s2;
       strcat(s1,s2);
       cout<<s1<<endl;
       break;

case 6:cout<<"enter string1 and string 2\n";
       cin>>s1>>s2;
       cout<<"enter a n number of char cant"<<endl;
       cin>>n;
       strcat(s1,s2,n);
       cout<<s1<<endl;
       break;

case 7:cout<<"enter a string"<<endl;
       cin>>s;
       my_strrev(s);
       cout<<s<<endl;
       break;

case 8:cout<<"enter a string"<<endl;
       cin>>s;
       my_strupper(s);
       cout<<s<<endl;
       break;

case 9:cout<<"enter a string"<<endl;
       cin>>s;
       my_strlower(s);
       cout<<s<<endl;
       break;

case 10:cout<<"enter a string"<<endl;
        cin>>s;
	cout<<"enter a char\n";
	cin>>ch;
        p=my_strchr(s,ch);
        if(p==0)
	cout<<"char is not present\n";
	else 
	cout<<"char is  present\n";
	break;

	
case 11:cout<<"enter a string"<<endl;
        cin>>s;
	cout<<"enter a char\n";
	cin>>ch;
        p=my_strrchr(s,ch);
        if(p==0)
	cout<<"char is not present\n";
	else 
	cout<<"char is  present\n";
	break;

case 12:cout<<"enter a  main string"<<endl;
        cin>>s1;
	cout<<"enter a sub string"<<endl;
	cin>>s2;
        p=my_strstr(s1,s2);
        if(p==0)
	cout<<"string is not present\n";
	else 
	cout<<"string is present\n";
	break;

case 13:cout<<"enter a string"<<endl;
        cin>>s;
        n=my_strlen(s);
	cout<<"len: "<<n<<endl;
	break;

case 14:exit(0);
      }
   } 

}

istream & operator >>(istream & in,String & s)
{
        cout<<"operator >> "<<endl;
	in>>s.p;
	return in;
}

ostream & operator <<(ostream &out,String s)
{
	cout<<"operator <<"<<endl;
	out<<s.p;
	return out;
}


void my_strcpy(String &s1,String s2)
{
	int i=0;
	for(i=0;s2.p[i];i++)
		s1.p[i]=s2.p[i];
}


void my_strncpy(String &s1,String s2,int n)
{
	int i=0;
	for(i=0;s2.p[i]&&i<n;i++)
	s1.p[i]=s2.p[i];
	s1.p[i]='\0';
}


int my_strcmp(String s1,String s2)
{
	int i=0;
	for(i=0;s1.p[i]&&s2.p[i];i++)
	{
	if(s1.p[i]!=s2.p[i])
	return s1.p[i]-s2.p[i];
	}
	return s1.p[i]-s2.p[i];
}

	
int my_strncmp(String s1,String s2,int n)
{
	int i=0;
	for(i=0;s1.p[i]&&s2.p[i]&&i<n;i++)
	{
	if(s1.p[i]!=s2.p[i])
	return s1.p[i]-s2.p[i];
	}
	return s1.p[i]-s2.p[i];
}


void strcat(String &s1,String s2)
{
	int i=0,j;
	for(i=0;s1.p[i];i++);
	for(j=0;s2.p[j];j++)
		s1.p[i++]=s2.p[j];
		s1.p[i]='\0';
}


void strcat(String &s1,String s2,int n)
{
	int i=0,j;
	for(i=0;s1.p[i];i++);
	for(j=0;s2.p[j]&&j<n;j++)
		s1.p[i++]=s2.p[j];
		s1.p[i]='\0';
}


void my_strrev(String &s)
{
	int len,i,j;
	char t;
	for(len=0;s.p[len];len++);
	for(i=0,j=len-1;i<j;i++,j--)
		{
		t=s.p[i];
		s.p[i]=s.p[j];
		s.p[j]=t;
		}
}



void my_strupper(String &s)
{
	int i=0;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]>='a'&&s.p[i]<='z')
		s.p[i]=s.p[i]-32;
	}
}


void my_strlower(String &s)
{
	int i=0;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]>='A'&&s.p[i]<='Z')
		s.p[i]=s.p[i]+32;
	}
}


char * my_strchr(String s,char ch)
{
	int i=0;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]==ch)
			return &s.p[i];
	}
	return 0;
}


char * my_strrchr(String s,char ch)
{

	int i,len=0; 
	for(len=0;s.p[len];len++);
	for(i=len-1;i>=0;i--)
	{
		if(s.p[i]==ch)
			return &s.p[i];
	
	}
	return 0;
}


char * my_strstr(String s1,String s2)
{
	int len=0,i,j=0,c=0,k;
	for(len=0;s2.p[len];len++);

	for(i=0;s1.p[i];i++)
	{
		if(s1.p[i]==s2.p[j])
		{
			for(k=i;s2.p[j];k++,j++)
			{
				if(s1.p[k]==s2.p[j])
					c++;
			}
		}
	if(c==len)
		return &s1.p[i];
	}
	return 0;
}


int my_strlen(String s)
{
	int i=0;
	for(i=0;s.p[i];i++);
	return i;
}

