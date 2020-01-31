//rahat choudery
#include <iostream>
using namespace std;
#include <fstream>
#include <list>
#include <iterator>

//create node
class Node
{
private:
  int deg;
  int coeff;
  
public:
  Node(int icoeff, int ideg) 
  { 
    coeff = icoeff; 
    deg = ideg;
  }
  
  int setUser_coeff(int a) 
  {
    coeff = a;
  } //set coeff to a
  
  int setUser_deg(int b) 
  {
    deg = b;
  } //set deg to b
  
  int getUser_coeff() 
  {
    return coeff;
  } //get user_coeff & return coeff

  int getUser_deg() 
  {
    return deg;
  } //get user_deg & return deg
  
  void print()
  {
    cout << coeff << "x^" << deg << " ";
  } //print the polynomial
};

void takeDerivative (list <Node> & pY, list <Node> & pX);
void subLists (list <Node> & pZ, list <Node> & pY, list <Node> & pX);

//main begins here
int main () 
{
  ifstream fin;
  int d;
  int user_deg;
  int user_coeff;
  list <Node> pX, pY, pZ; //declaration of all lists

  fin.open("poly_nums.txt"); //open the file
  
  if (fin.fail())
    {
      cout << "Error!";
    } //return an error if the file does not open

  fin >> d; //read in first number in set of numbers (the highest degree)
  while (!fin.eof())
    {  
      for (int x = 0; x < (d + 1); x++) //read in one polynomial at a time
	{
	  fin >> user_coeff >> user_deg; //read in pairs of coefficient and degree

	  if (user_coeff != 0) //ignore nodes that have a coefficient of zero
	    {
	    Node *n = new Node(user_coeff, user_deg);
	    pX.push_back(*n); //push new node into pX
	  }
	}

    //print the original polynomial (pX)
      list<Node>::iterator it;
      cout << "~The Original Polynomial: " << endl;
      for (it = pX.begin(); it != pX.end(); ++it)
	{
	  (*it).print();
	}
      cout << endl;

    //call the derivative function
    takeDerivative (pY, pX);

    //print derivative of polynomials (pY)
    cout << "~Taking the Derivative: " << endl;
    for (it = pY.begin(); it != pY.end(); ++it)
      {
	(*it).print();
      }
    cout << endl;
    pZ.clear();

    //call subraction function
    subLists (pZ, pY, pX);
    cout << "~Subtracting Derivative from Original: " << endl;
    
    //print subtracted polynomials (pZ)
    for (it = pZ.begin(); it != pZ.end(); ++it)
      {
	(*it).print();
      }
    cout << endl;
    cout << endl;

    //clear lists and read in highest degree of next polynomial
    pX.clear();
    pY.clear();
    pZ.clear();
    fin >> d;
    }
} //end main

//take derivative of original function
void takeDerivative (list <Node> &pY, list <Node> &pX)
{
  list<Node>::iterator it;
  for (it = pX.begin(); it != pX.end(); ++it)
    {
      Node temp =  *it;
      int coeff = temp.getUser_coeff();
      int deg = temp.getUser_deg();
      coeff = coeff * deg;
      deg = deg - 1;

      if (deg >= 0) //skip nodes with a degree >= 0
	{
	  Node *n = new Node(coeff, deg); 
	  pY.push_back(*n);
	}
    }
} //end function

//subtract derivative from original polynomial
void subLists (list <Node> &pZ, list <Node> &pY, list <Node> &pX)
{
  list<Node>::iterator ix, iy;
  for (ix = pX.begin(), iy=pY.begin(); ix != pX.end() && iy != pY.end(); ix) 
    {
      Node tempX = *ix;
      int coeffX = tempX.getUser_coeff();
      int degX = tempX.getUser_deg(); 
      
      Node tempY = *iy;
      int coeffY = tempY.getUser_coeff();
      int degY = tempY.getUser_deg();
      int coeffZ;
      
      if (degX == degY) { //degrees are equal
	coeffZ = coeffX - coeffY;
	int coeff = coeffZ;
	int deg = degX;
	Node *x = new Node(coeff, deg);
	pZ.push_back(*x);
	ix++;
	iy++;      
      }
      else if (degX > degY) { //degree in orignial > degree in derivative
	Node *x = new Node (0-coeffY, degY);
	pZ.push_back(*x);
	iy++;
      }
      else if (degX < degY) { //degree in original < degree in derivative
	Node *x = new Node (coeffX, degX);
	pZ.push_back(*x);
	ix++;
      }
    }
  Node *x = new Node ((*ix).getUser_coeff(), (*ix).getUser_deg());
  pZ.push_back(*x);

} //end of function
