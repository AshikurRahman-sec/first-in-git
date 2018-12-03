#include<bits/stdc++.h>
using namespace std;

int arr1[100][100];

struct valueandweight
{
    int weight;
    float value;
};



void knapsack(valueandweight arr[],int n,int a)
{
    int i,j,k,l,sum,maxm;
    for(i=0; i<n; i++)
    {
        for(j=0; j<=a; j++)
        {
            sum=0;
            if(i==0)
            {
                if(j<arr[i].weight)
                    arr1[i][j]=0;
                else
                    arr1[i][j]=arr[i].value;
            }
            else
            {
                if(j<arr[i].weight)
                    {arr1[i][j]=arr1[i-1][j];
                    }
                else
                {
                    sum=sum+arr[i].value+arr1[i-1][j-arr[i].weight];
                    if(sum>arr1[i-1][j])
                        k=sum;
                    else
                        k=arr1[i-1][j];
                    arr1[i][j]=k;
                }

            }
            cout<<arr1[i][j]<<"\t";
        }
    }
}

void sorting(valueandweight arr[],int n,int a)
{
    int i,j,k;
    valueandweight temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(arr[i].weight>arr[j].weight)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    knapsack(arr,n,a);
}

void input()
{
    int i,j,k,l,n,a;
    valueandweight arr[100];
    cin>>n>>a;
    for(i=0; i<n; i++)
        cin>>arr[i].value>>arr[i].weight;

    sorting(arr,n,a);
}

int main()
{
    input();

}
