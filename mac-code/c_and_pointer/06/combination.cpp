#include <unistd.h>
#include<iostream>

using namespace std;

const int num[10] = {1,2,3,4,5,6,7,8,9,10};
const int sum = 10;
const int n=10;

int main(int argc, char *argv[])
{
    int i,j;
    int result[sum+1]={0};
    int temp[sum+1]={0};

    for(i=0; i<n; i++)
    {
        if (num[i]>sum)
            continue;
        else
        {
            for(j=0; j<sum+1; j++)
            {
                temp[j]=result[j];
            }
            temp[0]=1;

            for(j=0;j<sum+1;j++)
            {
                if( (j+num[i])<=sum)
                {
                    result[j+num[i]] += temp[j];
                    printf("result[%d+num[%d]] = %d\n", j, i, result[j+num[i]]);
                }
            }
            sleep(3);
        }
    }

    cout<<result[sum];

    return 0;
}
