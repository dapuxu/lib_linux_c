�}��   ���n\q(3}	��F§a�uVA�s�H@�����9�������po*XԪ�ǁ��|	��%�H���H�r����[�P[���B�%��B��L��>c&��OM߯���*5��9 �a��4ɚ���/U�z���'Ք��'�y�����z�]ӲHg��D �`ap�5�Z�Ђx�Q�5�XGe1|� �dS��G
FD[��zQ"Kv��,�`j:5��������۶�2�WLczޢ��O�A؁T�S�{�|d�B-�p>'uߑ� ?�s=�o�T)I�4b���V��gwy/���o0�+�L�p���8~�#қZ=k1Ջ�[��0
��[�會�R��[�s��o�B;�~DHXp�\����R�d��;������Z~rS�W��V�I��6�Z�3������4	�7W2�;U�v�~U0L���Y�c�r��qlfݡ}T�H�$��}7n�ҧ����w%���հm6��c�&%H���Q��o̍���"���� $(SRC))
OBJ=$(patsubst %.c,%.o,$(DIR))

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) -static

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean cleanobj
cleanobj:
	rm  -f $(OBJ)
clean:
	rm  -f $(OBJ) $(TARGET)
