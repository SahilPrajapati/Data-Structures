#include<iostream>
using namespace std;

int main()
{
    int m,n;

    cout<<"Enter rows and columns of Sparse Matrix respectively."<<endl;
    cin>>m>>n;

    cout<<endl<<"Enter the Sparse Matrix."<<endl;

    int a[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }

    int Count=0;
    cout<<endl<<"The Matrix is :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"  ";

            if(a[i][j]!=0)
            {
                Count++;
            }
        }

        cout<<endl;

    }

    int p=Count+1;
    int q=3;

    int arr[p][q];

    arr[0][0]=m;
    arr[0][1]=n;
    arr[0][2]=Count;

    int temp=1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(a[i][j]!=0)
            {
                arr[temp][0]=i;
                arr[temp][1]=j;
                arr[temp][2]=a[i][j];
                temp++;
            }
        }

    }

    cout<<endl<<"The Column Form Representation is : "<<endl;

      for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

}
