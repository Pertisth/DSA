#include <iostream>


using namespace std;

class term
{
    public:
    int coeff;
    int exp;
};

class poly
{
    public:
    int n;
    term *t;
};

void create(poly *p)
{
    cout << "Enter no. of terms: ";
    cin >> p->n;
    p->t=new term[p->n];
    cout << "Enter the Terms "<<endl;
    for(int i=0;i<p->n;i++)
    {
        cin >> p->t[i].coeff;
        cin >> p->t[i].exp;
    }
}

void display(poly *p)
{
    for(int i=0;i<p->n;i++)
    {
        cout << p->t[i].coeff << "x" << p->t[i].exp << "+";

    }
}

struct poly *add(struct poly *p1 ,struct poly *p2)
{
    struct poly *sum;
    int i=0;
    int j=0;
    int k=0;
    sum = new poly;
    sum->t = new term[p1->n+p2->n];

    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].exp > p2->t[i].exp)
        {
            sum->t[k++]=p1->t[i++];
        }
        else if(p1->t[i].exp < p2->t[i].exp)
        {
            sum->t[k++]=p2->t[i++];
        }
        else
        {
            sum->t[k].exp=p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff+p2->t[j++].coeff;
        }
        for(;i<p1->n;i++)
        {
            sum->t[k++]=p1->t[i];
        }
        for(;j<p2->n;j++)
        {
            sum->t[k++]=p2->t[j];
        }
        sum->n = k;
        return sum;
    }

}



int main()
{
    poly p,p2,*p3;
    create(&p);
    display(&p);
    create(&p2);
    display(&p2);
    p3 = add(&p,&p2);
    display(p3);
    return 0;
}
