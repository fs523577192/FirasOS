import java.io.*;

public class Extract{
	private enum State{Null0, Null1, Cpp0, Cpp1, Cpp2, Cpp3, Cpp4,
		X86_0, X86_1, X86_2, X86_3, X86_4,
		X64_0, X64_1, X64_2, X64_3, X64_4,
		Java0, Java1, Java2, Java3, Java4,
		Head0, Head1, Head2, Head3, Head4,
		Comment0, Comment1, Comment2, Comment3, Comment4,
		Include0, Include1, Include2, Include3, Include4};
	// Null0 < Null1 cpp Cpp0 compiler="gcc" Cpp0 > Cpp1
	// < Cpp2 / Cpp3 cpp Cpp4 >
	public static void main(String args[]){
		try{
			FileReader fr = new FileReader(args[0]);
			String path = args[0].substring(0, args[0].indexOf((int)'.'));
			FileWriter fwCpp = new FileWriter(path + ".cpp");
			FileWriter fwX86 = new FileWriter(path + "_x86.asm");
			FileWriter fwX64 = new FileWriter(path + "_x64.asm");
			FileWriter fwJava = new FileWriter(path + ".java");
			StringBuilder sb = new StringBuilder();
			String str;
			State currentState = State.Null0;
			while(true){
				int i = fr.read();
				if(i == -1) break;
				
				if((char)i == '<'){
					str = sb.toString();
					if(currentState == State.Null0){
						currentState = State.Null1;
					}else if(currentState == State.Cpp1){
						fwCpp.write(str);
						currentState = State.Cpp2;
					}else if(currentState == State.X86_1){
						fwX86.write(str);
						currentState = State.X86_2;
					}else if(currentState == State.X64_1){
						fwX64.write(str);
						currentState = State.X64_2;
					}else if(currentState == State.Java1){
						fwJava.write(str);
						currentState = State.Java2;
					}else if(currentState == State.Include1){
						currentState = State.Include2;
						fwCpp.write("#include \"" + str + ".Cpp\"");
						fwX86.write("INCLUDE \"" + str + "_x86.asm\"");
						fwX64.write("INCLUDE \"" + str + "_x64.asm\"");
					}else if(currentState == State.Comment1){
						currentState = State.Comment2;
					}else if(currentState == State.Head1){
						currentState = State.Head2;
					}
					sb = new StringBuilder();
					sb.append((char)i);
				}else if((char)i == '>'){
					sb.append((char)i);
					str = sb.toString();
					if(currentState == State.Cpp0){
						currentState = State.Cpp1;
					}else if(currentState == State.X86_0){
						currentState = State.X86_1;
					}else if(currentState == State.X64_0){
						currentState = State.X64_1;
					}else if(currentState == State.Include0){
						currentState = State.Include1;
					}else if(currentState == State.Comment0){
						currentState = State.Comment1;
					}else if(currentState == State.Head0){
						currentState = State.Head1;
					}else if(currentState == State.Cpp1){
						fwCpp.write(str);
					}else if(currentState == State.X86_1){
						fwX86.write(str);
					}else if(currentState == State.X64_1){
						fwX64.write(str);
					}else if(currentState == State.Java1){
						fwJava.write(str);
					}else if(currentState == State.Cpp2){
						currentState = State.Cpp1;
						fwCpp.write(str);
					}else if(currentState == State.X86_2){
						currentState = State.X86_1;
						fwX86.write(str);
					}else if(currentState == State.X64_2){
						currentState = State.X64_1;
						fwX64.write(str);
					}else if(currentState == State.Java2){
						currentState = State.Java1;
						fwJava.write(str);
					}else if(currentState == State.Include2){
						currentState = State.Include1;
					}else if(currentState == State.Comment2){
						currentState = State.Comment1;
					}else if(currentState == State.Head2){
						currentState = State.Head1;
					}else if(currentState == State.Cpp3){
						currentState = State.Null0;
					}else if(currentState == State.X86_3){
						currentState = State.Null0;
					}else if(currentState == State.X64_3){
						currentState = State.Null0;
					}else if(currentState == State.Java3){
						currentState = State.Null0;
					}else if(currentState == State.Include3){
						currentState = State.Null0;
					}else if(currentState == State.Comment3){
						currentState = State.Null0;
					}else if(currentState == State.Head3){
						currentState = State.Null0;
					}else if(currentState == State.Cpp4){
						currentState = State.Null0;
					}else if(currentState == State.X86_4){
						currentState = State.Null0;
					}else if(currentState == State.X64_4){
						currentState = State.Null0;
					}else if(currentState == State.Java4){
						currentState = State.Null0;
					}else if(currentState == State.Include4){
						currentState = State.Null0;
					}else if(currentState == State.Comment4){
						currentState = State.Null0;
					}else if(currentState == State.Head4){
						currentState = State.Null0;
					}
					sb = new StringBuilder();
				}else if((char)i == '/'){
					sb.append((char)i);
					if(currentState == State.Cpp2){
						currentState = State.Cpp3;
					}else if(currentState == State.X86_2){
						currentState = State.X86_3;
					}else if(currentState == State.X64_2){
						currentState = State.X64_3;
					}else if(currentState == State.Java2){
						currentState = State.Java3;
					}else if(currentState == State.Include2){
						currentState = State.Include3;
					}else if(currentState == State.Comment2){
						currentState = State.Comment3;
					}else if(currentState == State.Head2){
						currentState = State.Head3;
					}
				}else{
					sb.append((char)i);
					if(currentState == State.Null1){
						if(sb.indexOf("cpp") >= 0){
							currentState = State.Cpp0;
						}else if(sb.indexOf("assemblyX86") >= 0){
							currentState = State.X86_0;
						}else if(sb.indexOf("assemblyX64") >= 0){
							currentState = State.X64_0;
						}else if(sb.indexOf("java") >= 0){
							currentState = State.Java0;
						}else if(sb.indexOf("include") >= 0){
							currentState = State.Include0;
						}else if(sb.indexOf("comment") >= 0){
							currentState = State.Comment0;
						}else if(sb.indexOf("head") >= 0){
							currentState = State.Head0;
						}
					}else if(currentState == State.Cpp3){
						if(sb.indexOf("cpp") >= 0){
							currentState = State.Cpp4;
						}
					}else if(currentState == State.X86_3){
						if(sb.indexOf("assemblyX86") >= 0){
							currentState = State.X86_4;
						}
					}else if(currentState == State.X64_3){
						if(sb.indexOf("assemblyX64") >= 0){
							currentState = State.X64_4;
						}
					}else if(currentState == State.Java3){
						if(sb.indexOf("java") >= 0){
							currentState = State.Java4;
						}
					}else if(currentState == State.Include3){
						if(sb.indexOf("include") >= 0){
							currentState = State.Include4;
						}
					}else if(currentState == State.Comment3){
						if(sb.indexOf("comment") >= 0){
							currentState = State.Comment4;
						}
					}else if(currentState == State.Head3){
						if(sb.indexOf("head") >= 0){
							currentState = State.Head4;
						}
					}
				}
			}
			fr.close();
			fwCpp.close();
			fwX86.close();
			fwX64.close();
			fwJava.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
