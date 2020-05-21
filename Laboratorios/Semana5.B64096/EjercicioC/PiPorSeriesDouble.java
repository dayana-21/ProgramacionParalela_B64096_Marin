
class SeriePorPartes implements Runnable {
    Long fin;
    Long inicio;
    int  sitioVector;


    public SeriePorPartes( long inicio, long fin, int svector ) {
        this.inicio = inicio;
        this.fin = fin;
        this.sitioVector = svector;
    }
    public void run() {
       double miSuma = 0;
       double alterna;

       alterna = ( 0 == ( inicio % 2 ) )? 4 : -4;
       for ( Long i = inicio; i < fin; i++ ) {
           miSuma += alterna/(2 * i + 1);
           alterna *= -1;
       }
       PiPorSeriesDouble.vectorPartes [sitioVector] = new Double(miSuma);
    }

}

public class PiPorSeriesDouble {

public static Double vectorPartes [] = new Double [10];

    public static void main( String[] args ) {
        long n = 100000;
        double x = 0;
        Thread thread[]  = new Thread[ 10 ];		
	if ( args.length > 0 ) {
           n = Long.parseLong( args[ 0 ] );
	}
        for ( int i = 0; i < 10; i++ ) {	
           vectorPartes[ i ] = new Double(0);
           Long inicio = i * n / 10;
           Long fin = (i+1)*n/10;
           thread[ i ] = new Thread( new SeriePorPartes( inicio, fin, i) );
           thread[ i ].start();
        }

        for ( int i = 0; i < 10; i++ ) {
           try {
              thread[ i ].join();
              x = x + vectorPartes[ i ].doubleValue();
           } catch ( InterruptedException e) {
           }
        }
        System.out.println( "Valor calculado de PI: " + x );
    }
}
