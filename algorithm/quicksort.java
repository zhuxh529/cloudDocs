import java.util.*;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class quicksort{
	public static int count;
	public static void main(String[] args){
		// int arr[]={3,2,5,4,1,10,7};
		// //int arr[]={4,3,2,1,5,7,6,8,9,10};
		// System.out.println(part2(arr, 0,arr.length-1));
		// //int arr1[]={4,3,2,1,5,7,6,8,9,10};
		// int arr1[]={3,2,5,4,1,10,7};
		// System.out.println(part(arr1, 0,arr1.length-1));
		// System.out.println(Arrays.toString(arr)+"   "+Arrays.toString(arr1));
		count=0;
		BufferedReader bf = null;
        try {
            bf = new BufferedReader(new FileReader("quicksrt.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("No such file!");
            e.printStackTrace();
            return;
        }
 
        int[] array = new int[10000];
        for (int i = 0; i < 10000; i++) {
            try {
                array[i] = Integer.parseInt(bf.readLine());
            } catch (NumberFormatException e) {
                e.printStackTrace();
                return;
            } catch (IOException e) {
                e.printStackTrace();
                return;
            }
        }


		int arr[]={3,2,5,4,1,11,7, 9,8, 0, 100, 99,88,77,66, 10};
		quicksrt(array, 0, array.length-1);
		//System.out.println(Arrays.toString(arr));
		int pre=0;
		System.out.println("count is:"+ count);
		for(int i =0;i<array.length;i++){
			if(pre>array[i]) System.out.println("index:" + i+" is not correct");
		}
	}

	public static void quicksrt(int arr[], int left, int right){
		if(right-left>0) {count+=(right-left);
		int p=part2(arr, left, right);
		if(left<p-1)
		quicksrt(arr, left, p-1);
		if(right>p+1)
		quicksrt(arr, p+1, right);
		}
	}

	public static int part2(int arr[], int left, int right){
		// int p=arr[left];
		// int i=left+1;
		// for(int j=left+1; j<=right;j++){
		// 	if(arr[j]<p){
		// 		swap(arr, i,j);
		// 		i++;
		// 	}
		// }
		// swap(arr, left, i-1);
		// return i-1;
		int pindex=right;

		int sub=right-left;
		// if(sub%2==0) pindex=(left+right)/2;
		// else pindex=(left+right)/2;

		if ((right - left + 1) % 2 == 0) {
            pindex = left + (right - left + 1) / 2 - 1;
        } else {
            pindex = left + (right - left + 1) / 2;
        }

        int pt1, pt2, pt3;
        int p=arr[pindex];

        pt1=arr[pindex]-arr[left];
        pt2=arr[right]-arr[pindex];
        pt3=arr[right]-arr[left];
        if(pt1*pt2<0){
        	if(pt1>0 && pt3>0){p=arr[right];swap(arr, right, left);}
        	if(pt1>0 && pt3<0){p=arr[left];}
        	if(pt1<0 && pt3>0){p=arr[left];}
			if(pt1<0 && pt3<0){p=arr[right];swap(arr, right, left);}

        	}
        else{
			p=arr[pindex];swap(arr, pindex, left);

        }


		
		int index=left+1;
		for(int j=left+1; j<=right;j++){
			if(arr[j]<p){
				swap(arr, index,j);
				index++;
			}
		}
		swap(arr, left, index-1);
		return index-1;
	}

	public static int partwiki(int arr[], int left, int right){
		int pindex=left;
		int p=arr[pindex];
		swap(arr, pindex, right);
		int index=left;
		for(int j=left; j<right;j++){
			if(arr[j]<p){
				swap(arr, index,j);
				index++;
			}
		}
		swap(arr, right, index);
		return index;
	}




	public static int part(int arr[], int left, int right){
		int i=left, j=right;
		int pindex=left;
		boolean sl=false, sr=false;
		int p=arr[left];
		while(i<=j){
			while(arr[i]<p) 
				i++;
			while(arr[j]>p) 
				j--;
			if(i<=j){
				if(arr[i]==p){ pindex=j;sl=true;}
				else if(arr[j]==p){pindex=i;sr=true;}
				swap(arr, i,j);
				i++;
				j--;
			}

		}
		// if(sl && arr[i]!=p) swap(arr, i, pindex);
		// if(sr&& arr[i]!=p) swap(arr, j, pindex);

		return i;
	}

	public static void swap(int arr[], int n1, int n2){
		int temp=arr[n1];
		arr[n1]=arr[n2];
		arr[n2]=temp;
	}

	public static int partition(int arr[], int left, int right)
	{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      pivot=arr[left];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
     
      return i;
	}
}
