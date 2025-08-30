#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
int n,i,j,k;
void menu(){
	char list[][20]={
	"Diamond",
	"Diamond hollow",
	"Downhill",
	"Hour glass",
	"Pascal's triangle",
	"Pyramid with number",
	"Spiral",
	"X"};
	int n = sizeof(list) / sizeof(list[0]);  // number of strings
    for(int i = 0; i < n; i++) {
        cout << i+1<<"."<<list[i] << endl;
    }
}
void printMatrix(const vector<vector<int> >& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void fillSpiral(vector<vector<int> >& a, int n) {
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int c = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            a[top][j] = c++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            a[i][right] = c++;
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                a[bottom][j] = c++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                a[i][left] = c++;
            }
            left++;
        }
    }
}
void spiral() {
    cout << "Enter a number: ";
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n, 0));
    fillSpiral(a, n);
    printMatrix(a); 
}
void hollowdiamond(){
	cout<<"Enter a number:";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<string((n-i),' ');
		for(j=0;j<=i*2;j++){
			if(j==0 || j==2*i)
			cout<<"*";	
			else
			cout<<" ";
		}
		cout<<endl;
	}
	for(i=n-2;i>=0;i--){
		cout<<string((n-i),' ');
		for(j=i*2;j>=0;j--){
			if(j==0 || j==2*i)
			cout<<"*";	
			else
			cout<<" ";
		}
		cout<<endl;
	}
}
void pyramid(){
	cout<<"Enter a number:";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<string(2*(n-i),' ');
		for(j=0;j<=i*2;j++){
			if(j<=i)
			cout<<j+1;
			else
			cout<<2*i-j+1;
			cout<<" ";
		}
		cout<<endl;
	}
}
void X(){
	cout<<"Enter a number:";
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j || i==n-j-1)
			cout<<"*";
			else
			cout<<" ";
		}
		cout<<endl;
	}
}
void hourglass(){
	cout<<"Enter a number:";
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<=(n-1)/2){
				if(i<=j && j<n-i)
				cout<<"*";
				else
				cout<<" ";
			}
			else{
				if(i>=j && j>=n-i-1)
				cout<<"*";
				else
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
void diamond(){
	cout<<"Enter a number:";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<string(2*(n-i),' ');
		for(j=0;j<=i*2;j++){
			if(j<=i)
			cout<<j+1;
			else
			cout<<2*i-j+1;
			cout<<" ";
		}
		cout<<endl;
	}
	for(i=n-2;i>=0;i--){
		cout<<string(2*(n-i),' ');
		for(j=i*2;j>=0;j--){
			if(j>=i)
			cout<<i*2-j+1;
			else
			cout<<j+1;
			cout<<" ";
		}
		cout<<endl;
	}
}
void downhill(){
    int a,b;
    cout << "Enter a number:";
    cin >> n;
    a=1;
    for(i=n;i>=1;i--) {
        cout << a<<"\t" ;
        b=a-i; 
        a+=i;
        for(j=i;j<n;j++) {
            cout << b <<"\t";
            b=b-j-1;
        }
        cout << endl;
    }
}
void pascaltriangle(){
    cout << "Enter a number:";
    cin >> n;
    vector <double> a;
    for(i=1;i<=n;i++){
    vector <double> b(i);
    for(k=n;k>=i;k--) {
        cout << " ";
    }
    for(j=0;j<i;j++){
        if(j==0 || j==(i-1)){
        b[j]=1;
        }
        else{
        b[j]=a[j]+a[j-1];
        }
    cout << b[j]<<" ";    
    }
    a=b;
    cout << endl;
    }
}
int main(){
	int ch;
	while(1){
		menu();
		cout<<"Enter your choice(Enter any character to exit):";
		cin>>ch;
		switch(ch){
			case 1:
				diamond();
				break;
			case 2:
				hollowdiamond();
				break;
			case 3:
				downhill();
				break;
			case 4:
				hourglass();
				break;
			case 5:
				pascaltriangle();
				break;
			case 6:
				pyramid();
				break;
			case 7:
				spiral();
				break;
			case 8:
				X();
				break;
			default:
				cout<<"Thankyou!";
				exit(0);
		}
		cout<<endl;
	}
	getch();
}
