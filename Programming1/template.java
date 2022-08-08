import java.io.*;

class Cereal {
    private static int count_matches(String M, String N, int K) {
        // Write your code here!
        return 0;
    }

    public static void main(String[] args) throws IOException {
        Reader sc = new Reader();
        int K = sc.nextInt();
        String M = sc.nextString();
        String N = sc.nextString();
        
        System.out.println(count_matches(M, N, K));
    }
    
    /* 
     * Fast input reader for Java.
     */
    private static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String nextString() throws IOException {
            byte c;
            while ((c = read()) <= ' ');
            StringBuilder str = new StringBuilder();
            do { str.append((char)c); }
            while ((c = read()) > ' ');
            return str.toString();
        }

        public int nextInt() throws IOException {
            byte c;
            while ((c = read()) <= ' ');
            int v = 0;
            do { v = (v << 3) + (v << 1) + (c ^ '0'); }
            while ((c = read()) >= '0' && c <= '9');
            return v;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) fillBuffer();
            return buffer[bufferPointer++];
        }
    }
}
