import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class bubble_sort {

	public static long bubble_sort1(int a[], int n) {
		long start = System.nanoTime();
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					// swap temp and arr[i]
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}

		}
		long end = System.nanoTime();
		long duration = end - start;
		return duration;
	}

	public static void reverse(int a[], int n) {
		int i, t;
		for (i = 0; i < n / 2; i++) {
			t = a[i];
			a[i] = a[n - i - 1];
			a[n - i - 1] = t;
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader bf = null;

		FileWriter fw = null;
		BufferedWriter bw = null;
		PrintWriter pw = null;
		try {
			bf = new BufferedReader(new FileReader("File 4sort.txt"));
			fw = new FileWriter("ans.txt", true);
			bw = new BufferedWriter(fw);
			pw = new PrintWriter(bw);
			int a[] = new int[250000000];
			String line;
			int k = 0;
			while ((line = bf.readLine()) != null) {
				a[k] = Integer.parseInt(line);
				// System.out.println(a[k]);
				k++;
			}
			reverse(a, k);
			for (int i = 0; i < 65536; i++) {
				System.out.println(a[i]);
			}

			long duration = bubble_sort1(a, k);

			System.out.println("total time of execution =  " + (duration));
			pw.println("bubble sort on File 6 in avg case takes time of = " + (duration) + " nano sec\n");

			pw.flush();

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				pw.close();
				bw.close();
				fw.close();
				bf.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

	}

}
