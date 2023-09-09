import java.util.*;
import java.lang.Thread;

class GradCode{
	static int times = 0;	
	String[] getGrayI(int n){
		if(n < 1) return null;

		int end = 0;
		String[] code = new String[1 << n];
		code[0] = "0";
		code[1] = "1";
		if(n == 1)
			return code;
		end = 2;

		for(int index = 2; index <= n; index++){
			//for(int position = 0; position < Math.pow(2,1); position++){
				//copy self from right to left which place with prefer end place			
				for(int j = 0 ; j < end; j++){
					times++;
					code[end + j] = '1' + code[end -1 - j];
					code[end - 1 -j] = '0' + code[end -1 -j];
				}
			//}
			end *= 2;
		}

		return code;
	}
	
/*
	public String[] getGray(int n) {
        if(n == 1){
            String[] grayCode = new String[]{"0","1"};
            return grayCode;
        } else if (n > 1){
            String[] preGrayCode = getGray(n -1);
            int len = preGrayCode.length;
            String[] grayCode = new String[2 * len];
            for (int i = 0; i < len; i++){
                grayCode[i] = '0' + preGrayCode[i];
                grayCode[i+len] = '1' + preGrayCode[len-1 -i ];
            }
            preGrayCode = null;
            return grayCode;
        }
        return null;
    	}
*/
	//wang
	
	public String[] getGrayW(int n){
		if(n == 1) return new String[]{"0", "1"};

		String[] init = new String[]{"0", "1"};
		//String[] now;
		for (int i = 1; i < n; i++){
			int len = init.length;
			String[] now = new String[len << 1];
			for (int j = 0; j < len; j++){
				now[j] = "0" + init[i];
				now[j + len] = "1" + init[len - j -1];
				times++;
			}
			init = now;
		}
		return init;

	}
	

	public static void main(String[] args){
		long start, end;
		long sumTime = 0;
		for(int i = 1; i < 26; i++){
			start = System.nanoTime();
			String[] code = (new GradCode()).getGrayI(i);
//			String[] code = (new GradCode()).getGrayW(i);
			code = null;			
			end = System.nanoTime();
			sumTime += end - start;
/*			System.out.print("[");
			for(String str:code){
				System.out.print("\"");
				System.out.print(str);
				System.out.print("\"");
				System.out.print(",");
			}
			System.out.println("]\n");
*/
		}
		int mb = 1024 * 1024;
		System.out.print("sumTime:");
		System.out.print(sumTime/1000000);
		System.out.print("ms\n");
		Runtime runtime = Runtime.getRuntime();
		System.out.println("Used Memory:"+(runtime.totalMemory() - runtime.freeMemory())/mb);
		System.out.println("times:"+times);
		/*
		try{
			Thread.sleep(50000);
		}
		catch(Exception e){
			
		}
		*/
	}

}
