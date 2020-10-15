import sys

class MinCoinChange:
    def minCoinDynamic(self, amount, coins):
        # this will store the optimal solution
        # for all the values -- from 0 to given amount.
        coinReq = [None] * (amount + 1)

        coinReq[0] = 0 # 0 coins are required to make the change for 0
        # now solve for all the amounts
        for amt in range(1, amount + 1):
            coinReq[amt] = sys.maxsize
            # Now try taking every coin one at a time and pick the minimum
            for j in range(0, len(coins)):
                if (coins[j] <= amt): # check if coin value is less than amount
                    # select the coin and add 1 to solution of (amount-coin value)
                    coinReq[amt] = min(coinReq[amt - coins[j]] + 1,coinReq[amt])
        #return the optimal solution for amount
        return coinReq[amount]

def main():
    coins = [1, 2, 3]
    amount = 20
    CoinChangeCalculator = MinCoinChange()
    print("Minimum Coins required to make change for " + str(amount) + " are: " + str(CoinChangeCalculator.minCoinDynamic(amount, coins)))

# Run the program
main()