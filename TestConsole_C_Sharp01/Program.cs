
// 플레이어와 컴퓨터가 각각 카드를 2장씩 뽑는다. 두 카드의 합이 더 큰 쪽이 승리. 작은 쪽은 패배한다.
// 동일한 숫자가 나올 경우 문양은 -> 스페이드, 하트, 다이아몬드, 클로버 순서로 승리한다.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace ConsoleApp1
{
    internal class CardGame
    {
        static void Main(string[] args)
        {
            int[] playerCardPack = new int[13];
            int[] computerCardPack = new int[13];
            int[] playerCardShape = new int[2];
            int[] computerCardShape = new int[2];

            int[] playerShapeNumber = new int[2];
            int[] computerShapeNumber = new int[2];

            string[] cardShape = new string[] { "♤", "♥", "◈", "♧" };
            int shuffleCount = 1000;

            firstCardPack(playerCardPack);
            firstCardPack(computerCardPack);

            //Console.WriteLine("플레이어의 카드팩");
            //printCardPack(playerCardPack);

            //Console.WriteLine("\n컴퓨터의 카드팩");
            //printCardPack(computerCardPack);

            Shuffle(playerCardPack, shuffleCount);
            Shuffle(computerCardPack, shuffleCount * 10);

            CardShape(playerCardShape, computerCardShape, playerShapeNumber, computerShapeNumber);

            //Console.WriteLine("\n플레이어의 셔플 후 카드팩");
            //AfterShuffle(playerCardPack);
            //Console.WriteLine("\n컴퓨터의 셔플 후 카드팩");
            //AfterShuffle(computerCardPack);

            CompareTwoNumbers(playerCardPack, computerCardPack, playerCardShape, computerCardShape, playerShapeNumber, computerShapeNumber);
        }

        // 카드팩에 값 넣기
        static void firstCardPack(int[] CardPack)
        {
            for (int i = 0; i < 13; i++)
            {
                CardPack[i] = i + 1;
            }
        }

        // 카드팩 출력
        static void printCardPack(int[] CardPack)
        {
            for (int i = 0; i < 13; i++)
            {
                Console.Write("{0} ", CardPack[i]);
            }
            Console.WriteLine();
        }

        // 카드팩 셔플
        static void Shuffle(int[] CardPack, int shuffleCount)
        {
            int temp = 0;
            Random random = new Random();
            int count = 0;

            while (count < shuffleCount)
            {
                for (int i = 0; i < CardPack.Length; ++i)
                {
                    int randomIdx = random.Next(0, CardPack.Length);
                    int randomIdx2 = random.Next(0, CardPack.Length);

                    temp = CardPack[randomIdx];
                    CardPack[randomIdx] = CardPack[randomIdx2];
                    CardPack[randomIdx2] = temp;

                }
                count++;
            }
        }

        // 셔플 후 플레이어 카드팩
        static void AfterShuffle(int[] CardPack)
        {
            for (int i = 0; i < 13; i++)
            {
                Console.Write("{0} ", CardPack[i]);
            }
            Console.WriteLine();
            Console.WriteLine();
        }

        // 카드 별 문양 정하기
        static void CardShape(int[] playerCardShape, int[] computerCardShape, int[] playerShapeNumber, int[] computerShapeNumber)
        {
            Random random = new Random();
            int playerRandomIdx = random.Next(1, 5);
            int playerRandomIdx2 = random.Next(1, 5);
            int computerRandomIdx = random.Next(1, 5);
            int computerRandomIdx2 = random.Next(1, 5);

            playerCardShape[0] = playerRandomIdx;
            playerCardShape[1] = playerRandomIdx2;

            playerShapeNumber[0] = playerRandomIdx;
            playerShapeNumber[1] = playerRandomIdx2;

            computerCardShape[0] = computerRandomIdx;
            computerCardShape[1] = computerRandomIdx2;

            computerShapeNumber[0] = computerRandomIdx;
            computerShapeNumber[1] = computerRandomIdx2;

        }



        // 플레이어의 카드팩 앞 두 숫자, 컴퓨터의 카드팩 앞 두 숫자의 합의 크기를 비교하기
        static void CompareTwoNumbers(int[] playerCardPack, int[] computerCardPack, int[] playerCardShape, int[] computerCardShape,
                                                                                            int[] playerShapeNumber, int[] computerShapeNumber)
        {
            // 카드 조작
            //playerCardPack[0] = 2;
            //playerCardPack[1] = 1;
            //computerCardPack[0] = 1;
            //computerCardPack[1] = 2;

            int sumPlayerNumbers = playerCardPack[0] + playerCardPack[1];
            int sumComputerNumbers = computerCardPack[0] + computerCardPack[1];


            // 문양, 카드 출력
            string[] cardShape = new string[] { "♤", "♥", "◈", "♧" };
            string[] playerShape = { "0", "0" };
            string[] ComputerShape = { "0", "0" };
            for (int i = 0; i < 2; i++)
            {
                if (playerCardShape[i] == 1)
                {
                    playerShape[i] = "♤";
                }
                else if (playerCardShape[i] == 2)
                {
                    playerShape[i] = "♥";
                }
                else if (playerCardShape[i] == 3)
                {
                    playerShape[i] = "◈";
                }
                else if (playerCardShape[i] == 4)
                {
                    playerShape[i] = "♧";
                }
            }
            for (int i = 0; i < 2; i++)
            {
                if (computerCardShape[i] == 1)
                {
                    ComputerShape[i] = "♤";
                }
                else if (computerCardShape[i] == 2)
                {
                    ComputerShape[i] = "♥";
                }
                else if (computerCardShape[i] == 3)
                {
                    ComputerShape[i] = "◈";
                }
                else if (computerCardShape[i] == 4)
                {
                    ComputerShape[i] = "♧";
                }
            }

            // 둘 중 더 큰 수가 앞에 나오게끔 하기
            int temp;
            if (playerCardPack[0] < playerCardPack[1])
            {
                temp = playerCardPack[0];
                playerCardPack[0] = playerCardPack[1];
                playerCardPack[1] = temp;
            }
            if (computerCardPack[0] < computerCardPack[1])
            {
                temp = computerCardPack[0];
                computerCardPack[0] = computerCardPack[1];
                computerCardPack[1] = temp;
            }


            Console.WriteLine("플레이어 카드 : {0}[{1}] {2}[{3}] \t 합 : {4}", playerShape[0], playerCardPack[0], playerShape[1], playerCardPack[1], sumPlayerNumbers);
            Console.WriteLine("컴퓨터 카드 : {0}[{1}] {2}[{3}] \t 합 : {4}", ComputerShape[0], computerCardPack[0], ComputerShape[1], computerCardPack[1], sumComputerNumbers);
            Console.WriteLine();

            if (sumPlayerNumbers > sumComputerNumbers)
            {
                Console.WriteLine("플레이어가 승리했습니다.");
                Console.WriteLine();
            }
            else if (sumComputerNumbers > sumPlayerNumbers)
            {
                Console.WriteLine("컴퓨터가 승리했습니다.");
                Console.WriteLine();
            }
            // 문양 비교 (
            else if (sumPlayerNumbers == sumComputerNumbers)
            {
                // 스 < 하 < 다 < 클
                if (playerShapeNumber[0] > computerShapeNumber[0])
                {
                    Console.WriteLine("플레이어가 승리했습니다.");
                    Console.WriteLine();
                }
                else if (computerShapeNumber[0] > playerShapeNumber[0])
                {
                    Console.WriteLine("컴퓨터가 승리했습니다.");
                    Console.WriteLine();
                }

            }

        }
    }
}
