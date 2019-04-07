#include <iostream>
#include <cmath>
using namespace std;
class nr_complex{
protected:
double re,im;
public:
    nr_complex():re(0),im(0) {}
    nr_complex(double r,double i):re(r),im(i) {}
    nr_complex(const nr_complex & nr){
    re=nr.re;
    im=nr.im;
    }
    void print(ostream & out){
    out<<re<<"+"<<im<<"i";
    }
    double modul(){
    return sqrt(re*re+im*im);
    }
    void get(istream & in){
    cout<<"partea reala ";
    in>>re;
    cout<<"partea imaginara ";
    in>>im;
    }
    friend ostream & operator << (ostream & out,nr_complex & nr);
    friend istream & operator >> (istream & in ,nr_complex & nr);
    nr_complex operator + (const nr_complex & b)const{
    double retmp=re+b.re;
    double imtmp=im+b.im;
    return nr_complex(retmp,imtmp);
    }
    bool operator == (nr_complex & b){
    return (re==b.re)&&(im==b.im)?true:false;
    }
    nr_complex operator * (const nr_complex & b)const{
    double retmp=re*b.re-im*b.im;
    double imtmp=re*b.im+im*b.re;
    return nr_complex(retmp,imtmp);
    }
    friend class vectorc;
    ~nr_complex(){}
};
class vectorc{
protected:
enum {capacitate=25};
int dim;
nr_complex v[capacitate];
public:
    vectorc(){
    for(int i=0;i<capacitate;i++)
        v[i]=nr_complex();
    dim=0;
    }
    vectorc(vectorc & a ){
    for(int i=0;i<a.dim;i++)
        v[i]=a[i];
    dim=a.dim;
    }
    nr_complex& operator [](int n){
    return v[n];
    }
    void modul(){
    for(int i=0;i<dim;i++)
    {   cout<<v[i]<<" are modulul egal cu "<<
        v[i].modul()<<endl;}
    }
    void suma(){
    nr_complex total;
    for(int i=0;i<dim;i++)
        total=total+v[i];
    cout<<"suma vectorului este ";
    cout<<total;
    }
    nr_complex operator * (vectorc & y){
    nr_complex total;
    for(int i=0;i<dim;i++)
        total=total+v[i]*y[i];
    return total;
    }
    void sortdupamodul(){
    for(int i=0;i<dim-1;i++)
        for(int j=i+1;j<dim;j++)
    if(v[i].modul()>v[j].modul()){
        nr_complex temp;
        temp=v[j];
        v[j]=v[i];
        v[i]=temp;
    }
    }
    friend ostream & operator << (ostream & out,vectorc & v);
    friend istream & operator >> (istream & in ,vectorc & v);
    ~vectorc(){}
};
class stiva:public vectorc{
public:
    stiva(){
    vectorc();
    }
    stiva(stiva & a){
    dim=a.dim;
    for(int i=0;i<a.dim;i++)
        v[i]=a.v[i];
    }
    void push(nr_complex & a){
    if(dim==capacitate)
        return;
    v[dim++]=a;
    }
    void pop(){
    if(dim==0)
        return;
    cout<<v[dim-1]<<"poped"<<endl;
    dim--;
    }
    friend ostream & operator << (ostream & out,stiva & s);
    friend istream & operator >> (istream & in ,stiva & s);
    ~stiva(){}
};
class coada:public vectorc{
int cap;
public:
    coada(){
    vectorc();
    cap=0;
    }
    coada(coada & c){
    dim=c.dim;
    for(int i=0;i<c.dim;i++)
        v[i]=c.v[i];
    cap=0;
    }
    void push(nr_complex & a){
    if(dim==capacitate)
        return;
    v[dim++]=a;
    }
    void pop(){
    if(cap==dim)
        return;
    cout<<v[cap++]<<" popped "<<endl;
    }
    friend ostream & operator << (ostream & out,coada & c);
    friend istream & operator >> (istream & in ,coada & c);
    ~coada(){};
};
int main()
{


}
ostream & operator << (ostream & out,nr_complex & nr){
nr.print(out);
return out;
}
istream & operator >> (istream & in ,nr_complex & nr){
nr.get(in);
return in;
}
istream & operator >> (istream & in ,vectorc & v){
nr_complex stop;
while(in){
    if(v.dim==v.capacitate)
        break;
    in>>v[v.dim];

    if(v[v.dim]==stop)
       break;
    v.dim++;

}
return in;
}
ostream & operator << (ostream & out,vectorc & v){
for(int i=0;i<v.dim;i++)
    out<<v[i]<<" ";
out<<endl;
return out;
}
ostream & operator << (ostream & out,stiva & s){
for(int i=0;i<s.dim;i++)
    out<<s.v[i]<<" ";
out<<endl;
return out;
}
istream & operator >> (istream & in ,stiva & s){
nr_complex stop;
while(in){
    if(s.dim==s.capacitate)
        break;
    in>>s[s.dim];

    if(s[s.dim]==stop)
       break;
    s.dim++;

}
return in;
}
ostream & operator << (ostream & out,coada & c){
for(int i=c.cap;i<c.dim;i++)
    out<<c.v[i]<<" ";
out<<endl;
return out;

}
istream & operator >> (istream & in ,coada & c){
nr_complex stop;
while(in){
    if(c.dim==c.capacitate)
        break;
    in>>c[c.dim];

    if(c[c.dim]==stop)
       break;
    c.dim++;

}
return in;
}
