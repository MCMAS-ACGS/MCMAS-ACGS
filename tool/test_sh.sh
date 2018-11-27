 # !/bin/bash
for i in $(seq 1 16)i
do
 echo "=== ${i} book store ==="
  # ISPL file
 in_filename="examples/book_store/book_store${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 0 -sat 0 ${in_filename}
done

for i in $(seq 1 16)
do
 echo "=== ${i} book store ==="
  # ISPL file
 in_filename="examples/book_store/book_store${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 1 -sat 0 ${in_filename}
done

for i in $(seq 1 16)
do
 echo "=== ${i} book store ==="
  # ISPL file
 in_filename="examples/book_store/book_store${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 0 -sat 1 ${in_filename}
done

for i in $(seq 1 16)
do
 echo "=== ${i} book store ==="
  # ISPL file
 in_filename="examples/book_store/book_store${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 1 -sat 1 ${in_filename}
done

for i in $(seq 33 64)
do
 echo "=== ${i} Bit transmission ==="
  # ISPL file
 in_filename="examples/bit_transmission_protocol/bit_transmission_protocol${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 0 -sat 0 ${in_filename}
done

for i in $(seq 33 64)
do
 echo "=== ${i} Bit transmission ==="
  # ISPL file
 in_filename="examples/bit_transmission_protocol/bit_transmission_protocol${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 0 -sat 1 ${in_filename}
done

for i in $(seq 33 64)
do
 echo "=== ${i} Bit transmission ==="
  # ISPL file
 in_filename="examples/bit_transmission_protocol/bit_transmission_protocol${i}.ispl"
  # Generate statistics
 ./MCMAS_ACGS -pg 1 -sat 0 ${in_filename}
done

for i in $(seq 33 64)
do
 echo "=== ${i} Bit transmission ==="
   ISPL file
 in_filename="examples/bit_transmission_protocol/bit_transmission_protocol${i}.ispl"
   Generate statistics
 ./MCMAS_ACGS -pg 1 -sat 1 ${in_filename}
done

for i in $(seq 3 10)
do
  echo "=== ${i} dining_cryptographers ==="
   # ISPL file
  in_filename="examples/dining_cryptographers/dining_cryptographers${i}.ispl"
   # Generate statistics
  ./MCMAS_ACGS -pg 0 -sat 0 ${in_filename}
done



for i in $(seq 3 10)
do
  echo "=== ${i} dining_cryptographers ==="
  # ISPL file
  in_filename="examples/dining_cryptographers/dining_cryptographers${i}.ispl"
   # Generate statistics
  ./MCMAS_ACGS -pg 1 -sat 0 ${in_filename}
done


./MCMAS_ACGS -pg 0 -sat 0 examples/castle/castle25.ispl #331
./MCMAS_ACGS -pg 0 -sat 0 examples/castle/castle27.ispl #333

./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle1.ispl #111
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle3.ispl #113 
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle7.ispl #131 
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle9.ispl #133
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle19.ispl #311 
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle21.ispl #313 
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle25.ispl #331 
./MCMAS_ACGS -pg 1 -sat 0 examples/castle/castle27.ispl #333 
