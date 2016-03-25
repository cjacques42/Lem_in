echo "\033[91mFichier vide: \033[39m"
./lem-in < test/vide
echo "\n\033[91mJuste un backslash_n: \033[39m"
./lem-in < test/backslash_n
echo "\n\033[91mDoublons de salles:\033[39m"
./lem-in < test/doublons
echo "\n\033[91mPas de salle sous la commande end:\033[39m"
./lem-in < test/no_end
echo "\n\033[91mPas de commande start ou end:\033[39m"
./lem-in < test/no_end_start
echo "\n\033[91mPas de liens:\033[39m"
./lem-in < test/no_links
echo "\n\033[91mPas de chemin:\033[39m"
./lem-in < test/no_path
echo "\n\033[91mLien avec une salle inexistante:\033[39m"
./lem-in < test/no_path_lien_avec_salle_inexistante
echo "\n\033[91mPas de salle sous la commande start:\033[39m"
./lem-in < test/no_room_under_start
echo "\n\033[91mJuste le nombre de fourmis et un lien:\033[39m"
./lem-in < test/no_rooms_start_end_nothing
echo "\n\033[91mPas de nombre de fourmis:\033[39m"
./lem-in < test/no_number_of_ants
echo "\n\033[91mNombre de fourmis negatif:\033[39m"
./lem-in < test/negative_number_of_ants
#echo "\nFonctionnel 1000 salles 100 fourmis: "
#./lem-in < test/test1000
echo "\n\033[92mFonctionnel plusieurs commentaires entre les lignes:\033[39m"
./lem-in < test/multi_comments
echo "\n\033[92mFonctionnel noms de salles avec tirets:\033[39m"
./lem-in < test/multi_tirets
