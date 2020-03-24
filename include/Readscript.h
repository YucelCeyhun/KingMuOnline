#ifndef	_READ_SCRIPT_H_
#define	_READ_SCRIPT_H_


static enum SMDToken 
{
	NAME, 
	NUMBER, 
	END, 
	COMMAND = '#',
	LP = '{',
	RP = '}',
	COMMA = ',',
	SEMICOLON = ';',
	SMD_ERROR
};

static FILE     *SMDFile;
static float    TokenNumber;
static char     TokenString[100];
static SMDToken CurrentToken;

static SMDToken GetToken()
{
	unsigned char ch;
	TokenString[0] = '\0';
	do
	{
		if ( (ch =(unsigned char)fgetc(SMDFile)) == (BYTE)EOF) return END;
		if (ch=='/' && (ch =(unsigned char)fgetc(SMDFile) )=='/')
		{
			while((ch != '\n') && (ch != (BYTE)EOF)) {			// 2003.09.02 H.J.I ¼öÁ¤
				ch = (unsigned char)fgetc(SMDFile);
			}

			if (ch == (BYTE)EOF)
				return END;
		}
	} while(  isspace(ch) );
	
	char *p, TempString[100];
	switch(ch)
	{	
	case '#':
		return CurrentToken = COMMAND;
	case ';':
		return CurrentToken = SEMICOLON;
	case ',':
		return CurrentToken = COMMA;
	case '{':
		return CurrentToken = LP;
	case '}':
		return CurrentToken = RP;
	case '0':	case '1':	case '2':	case '3':	case '4':
	case '5':	case '6':	case '7':	case '8':	case '9':
	case '.':	case '-':
		ungetc(ch,SMDFile);
		p = TempString;
		while ( (  (ch = getc(SMDFile) ) !=(BYTE)EOF) && (ch=='.' || isdigit(ch) || ch=='-') )
			*p++ = ch;
		*p = 0;
		TokenNumber = (float)atof(TempString);
		//			sscanf(TempString," %f ",&TokenNumber);
		return CurrentToken = NUMBER;
	case '"':
		p = TokenString;
		while ( (  (ch = getc(SMDFile) ) !=(BYTE)EOF) && (ch!='"'))// || isalnum(ch)) )
			*p++ = ch;
		if (ch!='"')
			ungetc(ch,SMDFile);
		*p = 0;
		return CurrentToken = NAME;
	default:
		if (isalpha(ch))	
		{
			p = TokenString;
			*p++ = ch;
			while ( (  (ch = getc(SMDFile) ) !=(BYTE)EOF) && (ch=='.' || ch=='_' || isalnum(ch)) )
				*p++ = ch;
			ungetc(ch,SMDFile);
			*p = 0;
			return CurrentToken = NAME;
		}
		return CurrentToken = SMD_ERROR;
	}
}

/*static SMDToken GetToken()
{
	char ch;
	char* p;
	char TempString[100];

	TokenString[0]=0;

	do
	{
		if ((ch=fgetc(SMDFile)) == -1)
		{
			return END;	// End of FILE (EOF)
		}
		else
		{	
			if (ch=='/')		// this is /
			{
				if((ch=fgetc(SMDFile)) == '/')
				{
					while ((ch != '\n') && (ch != -1))	// End of Line (EOL)
					{
						ch=fgetc(SMDFile);
					}
	
					if (ch == -1)
					{
						return END;	// End of FILE
					}
				}
			}
		}
	}
	while (isspace(ch) != 0);

	
	switch(ch)
	{

	case 0x23:	// #
		return CurrentToken=COMMAND;
		break;
	
	case 0x3B:	// ;
		return CurrentToken=SEMICOLON;
		break;
	
	case 0x2C:	// ,

		return CurrentToken=COMMA;
		break;
	
	case 0x7B:	// {
		return CurrentToken = LP;
		break;

	case 0x7D:	// }
		return CurrentToken = RP;
		break;
	// Nice Index Table :)	by Deathway
	// Numbers Case
	case 0x2D:	//-
	case 0x2E:	//.
	case '0':	//0
	case '1':	//1
	case '2':	//2
	case '3':	//3
	case '4':	//4		
	case '5':	//5
	case '6':	//6
	case '7':	//7
	case '8':	//8
	case '9':	//9
		ungetc(ch, SMDFile);
		p = TempString;
		
		while (((ch=getc(SMDFile)) != -1) && ((ch == 0x2E) || (isdigit(ch) != 0) || (ch == 0x2D)))  // 2e '.'  2D '-'
		{
			*p = ch;	// Construct a String
			p++;
		}		
		*p = 0;
		TokenNumber = atof( TempString);	// Select the first Byte as Main ID
		return CurrentToken  = NUMBER ;
		break;

	case '\"':	// "	String Case
		p=&TokenString[0];
		
		while (((ch=getc(SMDFile)) != -1 ) && (ch != 0x22))	// nice
		{
			*p = ch;
			p++;
		}
		if (ch != 0x22 )
		{
			ungetc(ch, SMDFile);
		}
		*p = 0;
		return CurrentToken = NAME;
		break;

	default:	// Others
		if (isalpha(ch))
		{
			p=&TokenString[0];
			*p=ch;
			p++;

			while ( ((ch=getc(SMDFile)) != -1) && ( (ch == 0x2E) || (ch == 0x5F) || (isalnum(ch) != 0) ) )
			{
				*p=ch;
				p++;
				
			}

			ungetc(ch, SMDFile);
			*p=0;
			CurrentToken=NAME;
			return CurrentToken;
		}
		else
		{
			return CurrentToken = SMD_ERROR; // '<'
		}
		break;

	}

	return NAME;
}
*/


#endif

