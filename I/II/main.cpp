        /*
          ���������� K-� ����� ������������������ 182764125216343...� ������� �������� ������ ���� ����������� �����
        */

        # include <stdio.h>
        # include <conio.h>

        int main ()
        {
          unsigned long
            b, // �����
            kub, // ��� �����
            a; //
          int
            d, // ����� ������������������ ����
            ts, // ����� ������������������
            k; // ������ �����
          printf ("������� ����� ����� ");
          scanf ("%i", & k);
          fflush (stdin);
          a = 1;
          d = 0;
          while (1)
          {
            kub = a * a * a;
            b = kub;
            while (b != 0)
            {
              d ++;
              //ts = b % 10;
              b /= 10;
            }
            if (d >= k)
            {
              b = kub;
              while (1)
              {
                ts = b % 10;
                if (d == k)
                {
                  printf ("ts = %i\n", ts);
                  getch ();
                  return 0;
                }
                b /= 10;
                d --;
              }
            }

            a ++;
          } 
        }
















