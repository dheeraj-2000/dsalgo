#include <iostream>
using namespace std;

class polynomial
{
        private :
                struct node
                {
                        float coefficient ;
                        int exponent ;
                        node *link ;
                } *p ;
        public :
                polynomial( ) ;
                void append_poly ( float c, int e ) ;
                void display_poly( ) ;
                void add_poly( polynomial &l1, polynomial &l2 ) ;
                ~polynomial( ) ;
} ;
polynomial :: polynomial( )
{
        p = NULL ;
}
void polynomial :: append_poly ( float c, int e )
{
        node *temp = p ;
        if ( temp == NULL )
        {
                temp = new node ;
                p = temp ;
        }
        else
        {
                while ( temp -> link != NULL )
                        temp = temp -> link ;
                temp -> link = new node ;
                temp = temp -> link ;
        }
        temp -> coefficient = c ;
        temp -> exponent = e ;
        temp -> link = NULL ;
}
void polynomial :: display_poly( )
{
        node *temp = p ;
        int f = 0 ;
 
        cout << endl ;
        while ( temp != NULL )
        {
                if ( f != 0 )
                {
                        if ( temp -> coefficient > 0 )
                                cout << " + " ;
                        else
                                cout << " " ;
                }
                if ( temp -> exponent != 0 )
                        cout << temp -> coefficient << "x^" << temp -> exponent ;
                else
                        cout << temp -> coefficient ;
                temp = temp -> link ;
                f = 1 ;
        }
}
void polynomial :: add_poly ( polynomial &l1, polynomial &l2 )
{
        node *z ;
        if ( l1.p == NULL && l2.p == NULL )
                return ;
        node *temp1, *temp2 ;
        temp1 = l1.p ;
        temp2 = l2.p ;
        while ( temp1 != NULL && temp2 != NULL )
        {
                if ( p == NULL )
                {
                        p = new node ;
                        z = p ;
                }
                else
                {
                        z -> link = new node ;
                        z = z -> link ;
                }
                if ( temp1 -> exponent < temp2 -> exponent )
                {
                        z -> coefficient = temp2 -> coefficient ;
                        z -> exponent = temp2 -> exponent ;
                        temp2 = temp2 -> link ;
                }
                else
                {
                        if ( temp1 -> exponent > temp2 -> exponent )
                        {
                                z -> coefficient = temp1 -> coefficient ;
                                z -> exponent = temp1 -> exponent ;
                                temp1 = temp1 -> link ;
                        }
                        else
                        {
                                if ( temp1 -> exponent == temp2 -> exponent )
                                {
                                        z -> coefficient = temp1 -> coefficient + temp2 -> coefficient ;
                                        z -> exponent = temp1 -> exponent ;
                                        temp1 = temp1 -> link ;
                                        temp2 = temp2 -> link ;
                                }
                        }
                }
        }
        while ( temp1 != NULL )
        {
                if ( p == NULL )
                {
                        p = new node ;
                        z = p ;
                }
                else
                {
                        z -> link = new node ;
                        z = z -> link ;
                }
                z -> coefficient = temp1 -> coefficient ;
                z -> exponent = temp1 -> exponent ;
                temp1 = temp1 -> link ;
        }
        while ( temp2 != NULL )
        {
                if ( p == NULL )
                {
                        p = new node ;
                        z = p ;
                }
                else
                {
                        z -> link = new  node ;
                        z = z -> link ;
                }
                z -> coefficient = temp2 -> coefficient ;
                z -> exponent = temp2 -> exponent ;
                temp2 = temp2 -> link ;
        }
        z -> link = NULL ;
}
polynomial :: ~polynomial( )
{
        node *q ;
        while ( p != NULL )
        {
                q = p -> link ;
                delete p ;
                p = q ;
        }
}
int main( )
{
        polynomial p1 ;
        p1.append_poly ( 1.4, 5 ) ;
        p1.append_poly ( 1.5, 4 ) ;
        p1.append_poly ( 1.7, 2 ) ;
        p1.append_poly ( 1.8, 1 ) ;
        p1.append_poly ( 1.9, 0 ) ;
        cout << "\nFirst polynomial:" ;
        p1.display_poly( ) ;
        polynomial p2 ;
        p2.append_poly ( 1.5, 6 ) ;
        p2.append_poly ( 2.5, 5 ) ;
        p2.append_poly ( -3.5, 4 ) ;
        p2.append_poly ( 4.5, 3 ) ;
        p2.append_poly ( 6.5, 1 ) ;
        cout << "\nSecond polynomial:" ;
        p2.display_poly( ) ;
        polynomial p3 ;
        p3.add_poly ( p1, p2 ) ;
        cout << "\nResultant polynomial: " ;
        p3.display_poly( ) ;
        return 0;
}
