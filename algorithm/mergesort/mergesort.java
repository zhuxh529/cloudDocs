
import java.util.*;

public class mergesort{
	public static void main(String[] args) {
		List<Integer> r=new ArrayList<Integer>();
		List<Integer> l=new ArrayList<Integer>();
		List<Integer> list1=new ArrayList<Integer>();

		int[] x={1,2,5,7,9};
		int[] y={3,4,8,10,20};
		int[] list={3,1,4,2,8,10,9,7,20};

		createList(l,x);
		createList(r,y);
		createList(list1,list);


		System.out.println(merge_sort(list1).toString());
		//appendList(3,r,l);
		//System.out.println(r.toString());
		

	}

	public static List merge_sort(List<Integer> list1){
		if(list1.size()<2) return list1;
		int m=list1.size()/2;
		List<Integer> l=ListRange(list1, 0, m);
		List<Integer> r=ListRange(list1, m, list1.size());
		return merge(merge_sort(r), merge_sort(l));
	}

	public static List<Integer> merge(List<Integer> l, List<Integer> r){
		int i,j;
		i=j=0;
		List<Integer> retList=new ArrayList<Integer>();
		while(i<l.size() && j<r.size()){
			if(l.get(i)<r.get(j)){
				retList.add(l.get(i));
				i++;
			}
			else{
				retList.add(r.get(j));
				j++;
			}
		}
		appendList(i, retList,l);
		appendList(j, retList,r);
		return retList;

	}


	public static void createList(List<Integer> l, int[] arr){
		for(int ele:arr){
			l.add(ele);
		}
	}

	public static void appendList(int idx, List<Integer> l,List<Integer> r){
		if(idx>=r.size()) return;
		for(int i=idx; i<r.size();i++){
			l.add(r.get(i));
		}

	}

	public static List<Integer> ListRange(List<Integer> list1, int start, int end){
		List<Integer> retList=new ArrayList<Integer>();
		for(int i=start; i<end; i++)
		{
			retList.add(list1.get(i));
		}
		return retList;

	}

}

