class Solution:
    def clearDigits(self, s: str) -> str:
        length = len(s)

        # for i in range(length):
        i = 0
        while( i < length):
            if s[i] >= '0' and s[i] <= '9':
                s = s[:i] + s[i+1:]
                for j in range(i-1,-1,-1):
                    if s[j] >= 'a' and s[j] <= 'z':
                        s = s[:j] + s[j+1:]
                        print(s)
                        break
                length = len(s)
                i = 0
            i += 1
        return s
        
def main():
	input_string = input("Enter the input string : ")
	obj = Solution()

	output_string = obj.clearDigits(input_string)
	print(f"Input : {input_string}")
	print(f"Output : {output_string}")

main()
