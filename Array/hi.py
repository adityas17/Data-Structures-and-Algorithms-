def main():
    N = int(input())
    #print(N)
    output = []
    index = 1
    display(solve(index,output,N),0)
    #a = solve(index,output,N)

def solve(index, output, N):
    line = input()
    if index % 2 == 0:
        inputNum = line.split()
        answer = square(inputNum,len(inputNum)-1,0)
        output.append(answer)
        #print(output)
    if index == N*2:
        return output 
    index+=1
    return solve(index,output,N)

def square(inputNum,index,sum):
    if index==-1:
        return sum
    if int(inputNum[index]) > 0:
        sum += int(inputNum[index])*int(inputNum[index])
    return square(inputNum,index-1,sum)

def display(output,index):
    if index==len(output):
        return
    print(output[index])
    display(output,index+1)

if __name__ == "__main__":
    main()