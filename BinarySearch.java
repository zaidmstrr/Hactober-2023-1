package Lab10;

public class BinarySearch {
    public static int binarySearch(int[] array,int low,int high,int key){
            int mid = (low+high)/ 2;
            if (high<low){return -1;}
           else if (array[mid] == key) {
                return mid;
            }
            else if ( key<array[mid]) {
                return binarySearch(array, low, mid - 1, key);
            }
            else if (key>array[mid]){
                return binarySearch(array, low+1, mid , key);
            }
return -1;

    }
    public static void main(String[] args) {
        int[] array={1,2,3,4,5,6,8};
int last= array.length-1;
int result=binarySearch(array,0,last,4);
if(result==-1){
    System.out.println("Not found");
}
else {
    System.out.println("Element is found at index :"+result);
}
    }
}
