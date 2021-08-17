import java.io.*;
import java.util.*;

public class test
{
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        /* 读取键盘输入字符串
        InputStreamReader inp;
        BufferedReader buf;
        String str1, str2;
        int num1, num2;

        inp = new InputStreamReader(System.in);
        buf = new BufferedReader(inp);

        System.out.print("请输入第一个数据：");
        str1 = buf.readLine();
        num1 = Integer.parseInt(str1);

        System.out.print("请输入第二个数据：");
        str2 = buf.readLine();
        num2 = Integer.parseInt(str2);
        System.out.print(num1 + "*" + num2 + "=" + (num1*num2));
        */
        /* 读取键盘输入整数
        Scanner reader = new Scanner(System.in);
        int num;
        if(reader.hasNextInt())
        {
            num = reader.nextInt();
            System.out.print(num);
        }
        else
            System.out.print("请输入整数！");
        */
        /* 求n1和n2的乘积
        String str1, str2;
        int num1;
        Float num2;
        Scanner reader = new Scanner(System.in);

        System.out.print("请输入第一个整数：");
        str1 = reader.nextLine();  // nextLine是把Enter当作结束符，只要遇到Enter就结束
        num1 = Integer.parseInt(str1);
        System.out.print("请输入第二个实数：");
        str2 = reader.next();  // next()是只有读到有效字符后才把空格或换行符作为结束符，而在读到之前会自动去掉
        num2 = Float.parseFloat(str2);

        System.out.println(num1 + "*" + num2 + "=" + (num1*num2));
        */
        /* 求从1加到n的和
        int n, i=1, sum=0;
        Scanner buf=new Scanner(System.in);

        do{
            System.out.print("请输入正整数：");
            n = buf.nextInt();
        }while(n <= 0);

        while(i <= n)
            sum += i++;

        System.out.println("1 + 2 + ··· + " + n + "=" + sum);
        */
        /* 求最大公约数
        int a, b, temp;
        String str1, str2;
        BufferedReader buf;
        buf = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("请输入第一个数 a = ");
        str1 = buf.readLine();
        a = Integer.parseInt(str1);

        System.out.print("请输入第二个数 b = ");
        str2 = buf.readLine();
        b = Integer.parseInt(str2);

        do{
            temp = a%b;
            a = b;
            b = temp;
        }while(temp != 0);
        System.out.print("最大公约数为：" + a);
        */
        /* 计算阶乘
        Scanner reader=new Scanner(System.in);
        int n=1, s=1, m;

        do{
            System.out.print("请输入一个大于1的整数：");
            m = reader.nextInt();
        }while(m <= 1);

        while(s < m)
        {
            s *= n;
            n++;
        }

        System.out.println("s = " + s/(n-1));
        System.out.println("n = " + (n-2));
         */
        /* 计算1~10的和
        int i, n=10, sum=0;

        System.out.print("Sum = ");
        for (i = n; i > 1; i--) {
            sum += i;
            System.out.print(i + "+");
        }
        System.out.print(i + "=" + (sum+i));
         */
        /*int i, j, k=1;

        System.out.print("2\t");
        for (i = 3; i < 100; i += 2)
        {
            j = 3;
            while (j<Math.sqrt(i) && (i % j != 0))
                j++;
            if (j > Math.sqrt(i))
            {
                System.out.print(i + "\t");
                k++;
                if(k%10 == 0)
                    System.out.println();
            }
        }
        System.out.println("\n共有" + k + "个素数");*/
        /*final int Max = 100;
        int j, k, n;
        System.out.print("2\t");
        n = 1;
        k = 3;
        do {
            j = 3;
            while (j<Math.sqrt(k) && (k % j != 0))
                j++;
            if (j > Math.sqrt(k))
            {
                System.out.print(k + "\t");
                n++;
                if(n%10 == 0)
                    System.out.println();
            }
            k = k + 2;
        } while(k <Max);
        System.out.println("\n共有" + n + "个素数");*/
        /*int i, max, sec;
        int[] a={8, 91, 50, 21, 7, 81, 55, 93};

        if (a[0] > a[1])
        {
            max = a[0];
            sec = a[1];
        }
        else
        {
            max = a[1];
            sec = a[0];
        }
        System.out.print("数组各元素为：" + a[0] + " " + a[1]);

        for(i = 2; i < a.length; i++)
        {
            System.out.print(" " + a[i]);
            if (a[i] > max)
            {
                sec = max;
                max = a[i];
            }
            else if (a[i] > sec)
                sec = a[i];
        }
        System.out.print("\n最大值：" + max);
        System.out.print("\n次最大值：" + sec);*/
        /*int N, S, M;
        Scanner reader = new Scanner(System.in);
        System.out.print("请输入参与人数：");
        N = reader.nextInt();
        System.out.print("请输入从第几个人开始：");
        S = reader.nextInt();
        System.out.print("请输入报数M：");
        M = reader.nextInt();
        System.out.print("参与者：");
        for (int x=1; x <= N; x++)
            System.out.print(x + " ");

        int i=S-1, g=1, k=N, j;
        int[] a = new int[N];
        for (int h=1; h <= N; h++)
            a[h-1] = h;
        System.out.print("\n出圈顺序为：");
        do {
            i += (M-1);  // 计算出圈人的下标
            while(i >= k)  // 控制i的范围在圈内剩余人数之内
                i -= k;
            System.out.print(a[i] + " ");
            for (j = i; j < k-1; j++)
                a[j] = a[j+1];
            k--;
            g++;
        }while (g <= N);*/
        /*final int N=13, S=3, M=5;
        int[] p=new int[13];  // 标记是否出圈
        int[] q=new int[13];  // 保存出圈顺序
        int i, j, k, n=0;
        k = S-2;
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= M; j++)
            {
                if(k == N-1)
                    k = 0;
                else
                    k++;
                if (p[k] == 1)
                    j--;
            }
            p[k] = 1;
            q[n++] = k+1;
        }

        System.out.print("\n出圈顺序为：");
        for(i = 0; i < N; i++)
            System.out.print(q[i] + " ");*/
        /*int[] a={1, 2, 3, 4, 5, 6};

        for (int b:a)
            System.out.print(b);*/
        /*int i, j, k, sum=0;
        int[][][] a={{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
        for (i = 0; i < a.length; i++)
            for (j = 0; j < a[i].length; j++)
                for (k = 0; k < a[i][j].length; k++)
                {
                    System.out.println("a[" + i + "][" + j + "][" + k + "] = " + a[i][j][k]);
                    sum += a[i][j][k];
                }
        System.out.println("sum = " + sum);*/
        Scanner reader = new Scanner(System.in);
        String str=new String();
        if (args.length > 0)
            str = args[0];
        else
            str = reader.nextLine();
        int n, i=0;
        boolean Y=true;
        System.out.println("str = " + str);
        n = str.length();
        char sChar, eChar;
        while (Y && (i < n/2))
        {
            sChar = str.charAt(i);
            eChar = str.charAt(n-i-1);
            if (sChar == eChar)
                i++;
            else
                Y = false;
        }
        if (Y)
            System.out.println("是回文串");
        else
            System.out.println("不是回文串");
    }
}