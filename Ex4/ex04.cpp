#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Book
{
private:
    //string m_book;
    string m_title, m_author, m_isbn;
    bool m_isValid;

    bool notEmpty(){
        return !m_title.empty()  &&  !m_author.empty();
    }
    bool isbnValid(){
    string isbn = m_isbn;
    isbn.erase(std::remove(isbn.begin(), isbn.end(), '-' ), isbn.end());
    if(isbn.size() != 10) return false;
    int modsum{0};
    for(int i = 0;i<10;i++) modsum += std::stoi(isbn.substr(i,1)) * (static_cast<int>(i)+1);
    return modsum % 11 == 0;
    }

public:
    Book(string title, string author, string isbn)
        :m_title(title), m_author (author), m_isbn(isbn){
        m_isValid = notEmpty(); 
        if (m_isValid==true){ 
        m_isValid = isbnValid(); 
        }
        }


    void getInformation(){
        cout<<"The name of the book is: "<<m_title<<" the autor is: "<<m_author<<" the isbn is:"<<m_isbn<<"the book validity is: "<< boolalpha <<m_isValid<<endl;
    }

    
    bool requestVadility(){
        return m_isValid;
    } 
};

class Library
{
private:
    vector<Book> store;

    void deleteBook(int entry){
    store.erase(store.begin()+entry);
    }

    
public:
    void addBook(Book book){
    store.push_back(book);
    }

    void printInventary(){
    for(int i=0; i < store.size(); i++){
    store[i].getInformation();
    }
    }

    void cleanup(){
    int i =0;
    while(i < store.size()){
    if (store[i].requestVadility()==false){
        deleteBook(i);
    }else{
        i++;
    }
    }
    }
   
};


main(){


// You have a bag of books
Book book1("Sams Teach Yourself C++", "Siddharta Rao", "0-7897-5774-5");
Book book2("C++ Primer", "Stanley B. Lippman", "0321714113");
Book book3("The C++ Programming Language", "Bjarne Stroustrup","0321563840");
Book book4("Programming Python", "Mark Lutz","0-596-15810-2");
Book book5("TIBITS AT HOME", "Betty Bossy","1-234-567-8");
Book book6("Thinking in Java", "","9780596009205");
Book book7("Multiple View Geometry in Computer Vision", "","1139449141");
Book book8("","Paul Kimmel","0-321-99278-4");


// Bring all the books to the library
Library lib; // Create instance of library
lib.addBook(book1);
lib.addBook(book2);
lib.addBook(book3);
lib.addBook(book4);
lib.addBook(book5);
lib.addBook(book6);
lib.addBook(book7);
lib.addBook(book8);


// Give an overview
lib.printInventary();

// Clean non-valid book
lib.cleanup();

cout<<"after cleanup \n";

// Overview again
lib.printInventary();


// Now only C++ books are left in the library
return 0;
}