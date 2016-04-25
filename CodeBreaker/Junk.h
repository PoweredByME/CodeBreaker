/*#include<iostream>
using namespace std;

class Box
{
private:

double lenght, width, height;
double Volume;

void calcVolume(){Volume=lenght*width*height;}

public:

Box(double lenght = 0.0 , double width = 0.0 , double height = 0.0 ):lenght(lenght), width(width), height(height)
{ calcVolume();}

double getVolume() const {return (this->Volume);}

friend bool operator==(const Box& lhs, const Box&rhs);
friend bool operator==(const double lhs, const Box&rhs);
friend bool operator==(const Box& lhs, const double rhs);
friend Box operator+(const Box& lhs, const Box& rhs);

Box operator-(const Box& rhs) const
{
    return (Box(this->lenght-rhs.lenght, this->width-rhs.width, this->height-rhs.height)) ;
}

};

bool operator==(const Box& lhs, const Box&rhs)
{
   return (lhs.getVolume()==rhs.getVolume()?true:false);
}

bool operator==(const double lhs, const Box& rhs ){return (lhs==rhs.getVolume()?true:false);}
bool operator==(const Box& lhs, const double rhs ){return (rhs==lhs.getVolume()?true:false);}

Box operator+(const Box& lhs, const Box& rhs)
{
     return (Box((lhs.lenght+rhs.lenght), (lhs.width+rhs.width), (lhs.height+rhs.height)));
}

int main()
{
Box a(10,10,10), b(2,2,2);
double a2 = 1000;
a==a2?cout<<"\nA is equal than B." : cout<<"\nA is not equal to B.";
Box b1 = a + b, b2 = a - b;
cout<<"\n the volume of b1 = " << b2.getVolume();
return 0;
}*/

/*
#include<iostream>
using namespace std;

class Matrix{

private:
int rows, columns;
double mat[100][100];

public:

Matrix(int rows = 1, int columns = 1):rows(rows), columns(columns){ mat[0][0] = 0;}
int getRows() const {return rows;}
int getColumns() const {return columns;}
void changeColumns(int columns){this->columns = columns;}
void changeRows(int rows){this->rows = rows;}


void Input(){

  for(int c = 0; c < rows ; c++)
  {
     for(int c1 = 0; c1 < columns ; c1++)
     {
      cout<< "Enter the element ["<<c+1<<"]["<<c1+1<<"] = ";
      cin>>mat[c][c1]; 
     }
  }

}

void enterElement(double element, int row, int columns)
{
    mat[row][columns] = element;
}

double getElement(int rows, int columns) const
{
    return mat[rows][columns];
}

void ShowMatrix()
{
    for(int c = 0 ; c < rows ; c++)
    {
       for(int c1 = 0; c1 < columns ; c1++)
       {
          cout<<"\t"<<mat[c][c1]; 
       }
       cout<<endl;
    }
}

Matrix(const Matrix& obj)
{
    this->rows = obj.rows; this->columns = obj.columns;
    for(int c = 0; c < this->rows ; c++)
    {
        for(int c1 = 0; c1<this->columns; c1++)
        {
          this->mat[c][c1] = obj.mat[c][c1];
        }
    }
}

friend Matrix addMatrix(const Matrix& m1, const Matrix& m2);
friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
friend bool operator==(const Matrix& lhs, const Matrix& rhs);
friend bool operator<(const Matrix& lhs, const Matrix& rhs);
friend bool operator<=(const Matrix& lhs, const Matrix& rhs);

Matrix operator++()
{
    for(int c = 0 ; c < this->rows; c++)
    {
       for(int c1 = 0 ; c1 < this->columns ; c1++)
       { 
           this->mat[c][c1] += 1;
       } 
    }
    return *this;
}

Matrix operator++(int)
{
     Matrix hold; hold = (*this);
     for(int c = 0 ; c <this->rows ; c++)
     {
     for(int c1 = 0 ; c1 < this->columns ; c1++)
        {
           this->mat[c][c1]++;
        }
     }
     return hold; 
}


};     //end class

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
   bool result = false;
   if(lhs.getRows()==rhs.getRows()&&lhs.getColumns() == rhs.getColumns())
   {
      int element = rhs.getRows() * lhs.getColumns();
      int correct = 0;
      for(int c = 0; c < lhs.getRows() ; c++)
      {
         for(int c1 = 0; c1 < rhs.getColumns() ; c1++)
         {
            lhs.getElement(c,c1) == rhs.getElement(c,c1)?correct++:0; 
         }
      }
      result = (correct==element);
   }  
   return result;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
   return addMatrix(lhs,rhs);
}

Matrix addMatrix(const Matrix& m1, const Matrix& m2)
{
     Matrix result;
     if(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns())
     {
       result = Matrix(m1.getRows(), m2.getColumns());
       for(int c = 0; c < m1.getRows() ; c++)
       {
          for(int c1 = 0; c1 < m2.getColumns() ; c1++)
          {
           result.enterElement(m1.getElement(c,c1)+m2.getElement(c,c1),c,c1);
          }
       }
     }
     else cout<<"\n THE ADDITION IS INVALID CHECK SIZES OF MATRICES. \n";
     return result;
}



int main()
{

Matrix a(2,2);
Matrix b(2,2);
a.Input();
b.Input();

if(a==b)
{
   cout<< "\nMatrix are equal. \n";
}


Matrix c = a + b;//addMatrix(a,b);


c.ShowMatrix();
++a;

a.ShowMatrix();
b.ShowMatrix();
b++;
cout<<"\nHello.\n";
b.ShowMatrix();
return 0;
}*/

/*
#include<iostream>
#include "Matrix.h"

int main()
{
  Matrix a(3,3), b(3,3);
  a.In();
  b.In();
  if(a==b)
  cout<< "\nYES.\n";
  Matrix  c = a * b;
  c.Out(); 
  Matrix d  = a - c;
  d+=c;
  d+=10;
  d.Out();
return 0;
}
*/
// calcutor
    /*    
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int choice = 0;

    while(choice != 4)
    {
    double number=0;
        cout<< "Enter the number = ";
        cin>>number;
        cout<<"\n1.arctan.\n2.arcCos.\n3.arcSin.\n4.end.\nEneter your choice = ";
        choice = 0;
        cin>>choice;
        if(choice == 1)
        {
            cout<<"\n Arctan = " << atan(number)*180/3.1456<<endl;
        }
        else if(choice == 2)
        {
            cout<<"\n ArcCos = "<<acos(number)*180/3.1456<<endl;
        }
        else if(choice ==3)
        {
              cout<< "\n ArcSin = "<< asin(number)*180/3.1456<<endl;
        }


    }
} //my calculator



// OHT 1 PRACTICE

/*
#include<iostream>
using namespace std;

class c{

private:

int a;

public :

friend int main();

};

void printPointer(void *ptr)
{
  cout<<"\nAddress in pointer = " << ptr;
}

void printPointerContents(void *ptr)
{
  cout<<"\n =  " << *(double*)ptr;  
}

int main()
{
c x;

cin>>x.a;
int *ptr1;
int number = 3;
ptr1 = &number;
long *ptr2;
long number1 = 99;
ptr2 = &number1;
double *ptr3;
double number2 = 33.333;
ptr3 = &number2;

printPointer(ptr1);
printPointer(ptr2);
printPointerContents(ptr1);

return 0;
}*/
/*
#include<iostream>
using namespace std;

class Saad
{
private:
int x;
public:

Saad(){}
Saad(int num){x = num;}

void Set(int x =0)
{this->x = x;}

int Get(){return x;}

~Saad()
{
cout<<"\nDestructor is called";
 
}


};


int main()
{

Saad a;
a.Set();
a.Get();
return 0;
}
*/


/*
#include<iostream>
using namespace std;

class Data{

private:

int x, y;

protected:

int a, b;

public:

int c,d ;

virtual int add() = 0;

};

class myData: Data {  //my data class inherits form Data;

protected:
public:

int add()
{
   a+b;
}


};

class myData1: Data
{

public:
int add()
{
 a+d;
}

};
int m
{

public:
}
*/
/*

#include<iostream>
using namespace std;

class Box
{
private:

int height, width;
mutable int lenght;
static bool close;
int* p;

public:

Box(int h=0, int w = 0 , int l = 0):height(h), width(w), lenght(l){ *p = 0 ;}
static bool getState(){return close;}
static void allBoxClosed(){ close = true;}
static void allBoxOpen(){close = false;}
int getVolume() const {return height* width* lenght;}
int getHeight() const {return height;}
int getWidth() const {return width;}
int getLenght() const {return lenght;}
void  changeLenght(int length)const {this->lenght=length;}
void changeWidth(int width) {this->width = width;}
void changeHeight(int height){this->height = height;} 
};

bool Box::close = false;

int main()
{
   Box *a = new Box(1,2,3);
   Box b = Box(2,2,2);
   const Box c = Box(3,3,3);

   cout<< "\n Volume of Box a = " << a->getVolume();
   cout<< "\n Volume of Box b = " << b.getVolume();
   cout<< "\n Volume of Box c = " << c.getVolume();

   c.changeLenght(4);
   a->allBoxClosed();
   Box::allBoxOpen();



   return 0;
}*/

/*

#include<iostream>
#include<string>
using namespace std;

class myClass
{
static string Buffer;
string message;
public:
myClass(string mess = " "): message(mess){}
void putMessage(){Buffer = Buffer + message;}
static void Display(){cout<<endl<<Buffer<<endl;}
static void ClearBuffer(){Buffer = "" ; }

};

string myClass::Buffer = " ";

int main()
{
myClass a("Hello "), b("Mr. "), c("Saad.");
a.putMessage(); b.putMessage(); c.putMessage();
myClass::Display();
myClass::ClearBuffer();
myClass::Display();

}*/



/*
class s{

public:
friend int xxx();

friend s operator+(s lhs, s rhs);

};

s operator+(s lhs, s rhs)
{

}

int xxx(){

}
*/

/*
#include<iostream>
#include<string>
using namespace std;

class Vehical   // parent class
{
      private:
      string Color; 
      protected:
      //static a= 6;
      string type;
      public:
      int Capacity;
      Vehical(){Capacity = 0;}
      void setColor(string c){Color = c;}

};

class Car: public Vehical // d
{
    public: 
    void setColor(string x){}
};

class Truck : public Vehical{

};

class Airplane : public Vehical{

};

void Fucku (Vehical x)
{
  cout << "No ERROR";
}


int main()
{
Car a;
a.setColor("S");
Truck b;
Airplane c;
Fucku(a);
Fucku(b);
//b.setColor("s");
return 0;
}
*/

/*

#include<iostream>
using namespace std;

class A 
{

public:
void x() {cout << endl << " A: x.";}
virtual void y() {cout << endl << "A: y";}

};

class B : public A 
{

public:
void x() {cout << endl << "B: x";}
virtual void y() {cout << endl << "B: y";}

};


int main ()
{

B b;
A *ap = &b;
B *bp = &b;

b.x();
b.y();

bp->x();
bp->y();

ap->x();
ap->y();

return 0;
}*/

/*
#include <iostream>
#include <string>

using namespace std;

class Student
{

private:
string F_name;
string L_name;
int ID;

public:
Student(){}
Student(string s1 , string s2 , int id){
    F_name = s1;
    L_name = s2;
    ID = id;

    cout << endl << "Student called";
}

void Print()
{
     cout << "\nStudent:-\n";
     cout << "Name = " << F_name << " " << L_name;
     cout << endl << "ID = " << ID; 
}

};

class Grad_Student: private Student
{
private:
string dept;
string thesis;

public :
Grad_Student(){}
Grad_Student(string s1, string s2 , int id, string s3 , string s4): Student(s1, s2 , id)
{
   dept = s3;
   thesis = s4;
   cout << "Grad_Student called";
}

using Student :: Print;

void Print()
{
   Student:: Print();
   cout << endl << "Department = " << dept;
   cout << endl << "Thesis = " << thesis;
}
};

int main()
{
Student a  = Student("Saad", "Ahmad" , 122332);
Grad_Student b = Grad_Student("Saad", "Ahmad", 122332, "SEECS", "OpenCV");
a.Print();
b.Print();
return 0 ;
}*/
/*

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Person{

private:
string name;
string age;
public :
Person(){}
Person(string Name, string Age){
name = Name;
age = Age;
}
void Print()
{
cout << endl << "Name = " << name;
cout << endl << "Age = " << age;
}

};

class Employ
{
private:
string dept;
string pay;
public:
Employ(){}
Employ(string d, string p) 
{
dept = d;
pay =  p;
}
void Print()
{
cout << endl <<"Department = " << dept;
cout << endl << "Pay = " << pay;
}
};

class Teacher: public Person, public Employ
{
private:
string school;
public :
Teacher(){};
Teacher(string name, string age, string dept, string pay, string School):
Person(name, age), Employ(dept , pay)
{
   this->school =School;
}

void Print()
{
    Person::Print();
    Employ::Print();
    cout << endl << "School = " << school;
}

};
int main()
{
  vector<void*> theList;
  Employ *b = new Employ("EE", "122222");
  Person *c = new Person("Saad Ahmad", "12");
  Teacher *a = new Teacher("Saad Ahmad", "12", "EE", "12222", "NUST");
  theList.push_back(a);theList.push_back(c);theList.push_back(b);
  for(int c = 0 ; c < theList.size(); c++)
  {
     theList[c]->Print();
     delete theList[c];
  } 
  return 0;
}

*/

/*

#include<iostream>
#include<string>

using namespace std;


class Person
{
private:
string name;
string age;
public:
Person()
{
   cout << endl << "Person default constructor is called";
}
Person(string name, string age)
{
   this->name = name;
   this->age = age;
   cout << endl << "Person parameterized constructor is called.";
}
void setName(string name){this->name = name;}
void setAge(string age){this->age = age;}
string getName(){return name;}
string getAge(){return age;}
~Person (){cout << endl << "Person destructor is called";}
void Print(){
 cout << endl << "Person :-";
 cout << endl << "Name = " << this->name;
 cout << endl << "Age = " << this->age;
}
};

class Teacher: virtual public Person
{
  private:
  string school;
  public:
  Teacher(){    //default constructor
   cout <<endl<< "Teacher constructor is called.";
  }
  Teacher(string name, string age, string school) :Person (name , age)  // parameterized constructor
  {
    this->school = school;
    cout << endl << "Teacher constructor called (Parameterized)";

  }

  void setSchool(string school)
  {
     this->school = school; 
  }

  string getSchool(){return school;}

  void Print()
  {
     cout << endl << "Teacher :-";
     cout << endl << "Name = "<< this->Person::getName();
     cout << endl << "Age = " << this->Person::getAge();
     cout << endl << "School = " << this->school;
  }

  ~Teacher()
  {
    cout << endl << "Teacher destructor is called.";
  }

};

class Author: virtual public Person
{
   private:
   string book;
   public:
   Author(){   //defualt constructor
     cout << endl << "Author constructor is called.";
   }
   Author(string name, string age , string book): Person(name, age) //parameterized constructor
   {
      this->book = book;
      cout << endl << "Author constructor is called (Paramertize)";
   }

   void setBook(string book){this->book = book;}

   string getBook(){return book;}
   void Print()
   {
     cout << endl << "Author:-";
     cout << endl << "Name = " << this->Person::getName();
     cout << endl << "Age = " << this->Person::getAge();
     cout << endl << "Book = " << this->book;
   }
   ~Author()
   {
    cout << endl << "Author destructor is called.";
   }
};

class Scholar:virtual public Teacher, virtual public Author
{
   public:
   Scholar(){
     cout << endl << "Scholar default constructor is called.";
   }
   Scholar(string name, string age , string school, string book)
   {
      this->Teacher::setName(name);
      this->Teacher::setAge(age);
      this->Author::setName(name);
      this->Author::setAge(age);
      this->Teacher::setSchool(school);
      this->Author::setBook(book);
      cout << endl << "Scholar parameterized constructor is called";
   }

   void setName(string name)
   {
   this->Teacher::setName(name);
   this->Author::setName(name);
   }
   void setAge(string age)
   {
   this->Teacher::setAge(age);
   this->Author::setAge(age);
   } 
   void setBook(string book)
   {
   this->Author::setBook(book);
   }
   void setSchool(string school)
   {
   this->Teacher::setSchool(school);
   }

   string getName(){return Teacher::getName();}
   string getAge(){return Teacher::getAge();}
   string getBook(){return Author::getBook();}
   string getSchool(){return Teacher::getSchool();}

   void Print()
   {
      cout << endl << "Scholar:-";
      cout << endl << "Name = " << this->Teacher::getName();
      cout << endl << "Age = " << this->Teacher::getAge();
      cout << endl << "Book = " << this->Author::getBook();
      cout << endl << "School = " << this->Teacher::getSchool();
   }

   ~Scholar()
   {
     cout << endl << "Scholar destructor is called.";
   }
};

int main()
{

Teacher b = Teacher("Saad", "15", "Seecs");
b.Print();
cout << endl << "__________________________";
Scholar a = Scholar("Saad", "17", "SEECS","MYBook");
a.Print();

return 0;
}

class StreamWriter
{
  private:
  ofstream Writer;
  string filePath;
  bool Opened;
  public:
  StreamWriter(){}
  StreamWriter(string filePath)
  {
     Opened = true;
     this->filePath = filePath;
     Writer.open(this->filePath);
     if(!Writer)
     {
        Opened = false;
     }
  }

  void OpenFile(string filePath)
  {
      Opened = true;
      this->filePath = filePath;
      Writer.open(this->filePath);
      if(!Writer)
      {
         Opened = false;
      }
  }

  bool isOpened(){return Opened;}
  void reWrite(string stringToWrite)
  {
      Writer << stringToWrite;
  }

  ofstream& getOfStream(){return Writer;}
};

class StreamReader
{
private:
ifstream Reader;
string filePath;
bool Opened;
public:
StreamReader(){}
StreamReader(string filePath)
{
   Opened = true;
   this->filePath = filePath;
   Reader.open(this->filePath);
   if(!Reader)
   {
   Opened = false;
   }
}

bool isOpened(){return Opened;}

void OpenFile(string filePath)
{
   Opened = true;
   this->filePath = filePath;
   Reader.open(this->filePath);
   if(!Reader)
   {
   Opened = false;
   }
}

string CompleteRead()
{
  string contents;
  Reader >> contents;
  return contents;
}

ifstream& getIfStream(){return Reader;}

};


*/
