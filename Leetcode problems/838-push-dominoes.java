class Solution {
    private void process_string(StringBuilder sb,int start,int end,char content){
        for(int i = start ; i < end ; i++){
            sb.setCharAt(i,content);
        }
    }
    private void process_middle(StringBuilder sb,int start,int end){
        // R ... L case
        while(start<end){
            sb.setCharAt(start,'R');
            sb.setCharAt(end,'L');
            start++;
            end--;
        }
    }
    public String pushDominoes(String dominoes) {
        StringBuilder sb = new StringBuilder(dominoes);
        int slide_right = 0;
        int first_ptr = 0;
        if(dominoes.charAt(0)=='.'){
            for(slide_right=1 ; slide_right < dominoes.length() ; slide_right++){
                if(dominoes.charAt(slide_right)!='.'){
                    if(dominoes.charAt(slide_right)=='L'){
                        process_string(sb,0,slide_right,'L');
                    }
                    else{
                        first_ptr = slide_right;
                        break;
                    }
                }
            }
        }
        for( ; slide_right < dominoes.length() ; slide_right++){
            if(dominoes.charAt(slide_right)!='.'){
                //if two pointers are not in same state
                if(slide_right!=first_ptr){
                    if(dominoes.charAt(first_ptr)=='R' && dominoes.charAt(slide_right)=='L')
                    {
                        process_middle(sb,first_ptr,slide_right);
                    }
                    else if (dominoes.charAt(first_ptr)=='R' && dominoes.charAt(slide_right)=='R'){
                        process_string(sb,first_ptr,slide_right,'R');
                    }
                    else if(dominoes.charAt(first_ptr)=='L' && dominoes.charAt(slide_right)=='L'){
                        process_string(sb,first_ptr,slide_right,'L');
                    }
                    first_ptr = slide_right;
                }
            }
        }
        // end L ... 
        // end R ...
        if(first_ptr+1!=slide_right){
            if(dominoes.charAt(first_ptr)=='R')
                process_string(sb,first_ptr,dominoes.length(),'R');
        }
        return sb.toString();
    }
}
