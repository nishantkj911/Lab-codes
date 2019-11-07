import java.util.Scanner;

public class Mixer {
    
    int arr[];
    int size;
    
    static Scanner input = new Scanner(System.in);
    
    void accept()
    {
        System.out.print("Length..");
        size = input.nextInt();
        System.out.println("Enter elements in ascending order without duplicates");
        arr = new int[size];
        for(int i=0; i<size; i++)
        {
            input.nextInt();
        }  
    }
    
    Mixer mix(Mixer A)
    {
        Mixer result = new Mixer();
        
        result.size = this.size + A.size;
        result.arr = new int[result.size];
        for(int i=0, thiI = 0, AI = 0; i<result.size;i++)
        {
            if(this.arr[thiI] < A.arr[AI])
            {
                result.arr[i] = this.arr[thiI];
                thiI++;
            }
            else if(this.arr[thiI] > A.arr[AI])
            {
                 result.arr[i] = A.arr[AI];
                AI++;
            }
            else
            {
                 result.arr[i] = this.arr[thiI];
                 result.arr[i++] = A.arr[AI];
                 thiI++;
                 AI++;
            }
        }
        
        return result;
    }
    
    void display()
    {
        for(int i=0; i<this.size; i++)
        {
            System.out.print(this.arr[i] + "\t");
        }
        System.out.println();
    }
}
