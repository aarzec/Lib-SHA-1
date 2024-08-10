package ejemplos.java;

public class Main {
    static {
        try {
            System.load("/home/kmd/Documents/GitHub/Lib-SHA-1/ejemplos/java/libsha1.so");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load.\n" + e);
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        SHA1Lib sha1 = new SHA1Lib();
        byte[] output = new byte[20];
        sha1.sha1_hash("Hola Mundo!", output);
        for (int i = 0; i < output.length; i++) {
            System.out.printf("%02x", output[i]);
        }
        System.out.println();
    }
}
