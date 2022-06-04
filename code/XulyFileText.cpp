// Minh hoa xu ly file
#include<stdio.h>

// Ham doc mang 1 chieu tu file
void ReadArray(char *fname, int a[], int &n)
{
	FILE *fp = fopen(fname, "rt"); // mo file de doc (r) dang text (t)
	if(fp == NULL)
		printf("Khong mo duoc file!");
	else
	{
		// Doc n
		fscanf(fp, "%d", &n);
		// Doc cac phan tu cua mang
		for(int i=0; i<n;i++)
			fscanf(fp, "%d", &a[i]);
		fclose(fp);
	}
}

// Ham ghi mang vao file
void WriteArray(char *fname, int a[], int n)
{
	FILE *fp = fopen(fname, "wt"); // mo file de ghi (w) dang text (t)
	if(fp == NULL)
		printf("Khong mo duoc file!");
	else
	{
		// ghi n
		fprintf(fp, "%d\n", n);
		// Ghi cac phan tu cua mang
		for(int i=0; i<n;i++)
			fprintf(fp, "%d ", a[i]);
		fclose(fp);
	}
}


void PrintArray(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}

void SortArray(int a[], int n)
{
	for(int i=0; i<n-1; i++)	
		for(int j=i+1; j < n; j++)
			if(a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

int main()
{
	int a[100], n;
	
	ReadArray("D:\\array.txt", a, n);
	printf("Mang doc tu file:\n");
	PrintArray(a, n);
	printf("\nMang da sap xep tang dan:\n");
	SortArray(a, n);
	PrintArray(a, n);
	// Luu mang da sap xep vao file moi:
	WriteArray("d:\\array1.txt",a ,n);
}
