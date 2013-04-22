/*

Code for generating a 'sorta' 2d array -- the Vignere matrix
Modified from source code taken from http://www.daniweb.com/software-development/java/threads/269840/2d-char-array-vigenere-cipher
Post #3

*/

class printVigMatrix{
    public static void main(String[] args) {
    	char[] alphabet = {'A','B','C','D','E','F','G','H','I','J','K',
    		'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    	
	System.out.println(alphabet.length);
    	char[][] array =createTable(alphabet);
    	printTable(array);
    }

    private static char[][] createTable(char[] alphabet) {
    	char[][] table = new char[alphabet.length][alphabet.length];
    	int a;
    	for(int i = 0; i < alphabet.length; i++){
    		for(int j = 0; j < alphabet.length; j++){
    			a = i+j;
    			if(a >= alphabet.length){
    				a = a - alphabet.length;
    			}
    			table[i][j] = alphabet[a];
    		}
    	}
    	return table;
    }

    private static void printTable(char[][] table) {
    	for(int i = 0; i < table.length; i++){
    		System.out.print("{");
		for(int j = 0; j < table.length; j++){
    			System.out.print("'"+table[j][i]+"'");
			if (j!=table.length-1){
				System.out.print(",");
			}
    		}
		System.out.println("}");
    		}
    	}
 }
