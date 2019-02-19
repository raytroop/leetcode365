//https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4?toCommentId=23935
int jumpFloor(int num){
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    if(num == 2)
        return 2;

    int minus_2 = 1, minus_1 = 2, curr;
    for(int i = 3; i < num; ++i){
        curr = minus_2 + minus_2;
        minus_2 = minus_1;
        minus_1 = curr;
    }

    return curr;
}