^d::
	send ^s
	anc = %clipboard%
	clipboard = make test
	controlclick,x200 y200,root@server: /var/42,,R
	controlsend,,{enter},root@server: /var/42
	clipboard = %anc%
return

^e::
	send ^s
	fileread,fichier,\\SERVER\serv\var\42\end
	anc = %clipboard%
	clipboard = make test
	controlclick,x200 y200,root@server: /var/42,,R
	controlsend,,{enter},root@server: /var/42
	Loop 200
	{
		fileread,fichierr,\\SERVER\serv\var\42\end
		if (fichierr != fichier)
			break
		
		sleep 50
	}
	controlclick,x80 y64,Dez C html Console
	clipboard = %anc%
return